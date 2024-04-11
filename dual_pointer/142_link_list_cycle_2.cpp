#include <iostream>
#include <unordered_set>

using namespace std;


class MyLinkedList {
public:
	struct ListNode {
		int val;
		ListNode *next;

		ListNode() : val(0), next(nullptr) {};

		ListNode(int x) : val(x), next(nullptr) {};

		ListNode(int x, ListNode *ptr) : val(x), next(ptr) {};
	};

	MyLinkedList() {
		virtual_head = new ListNode();
		size = 0;
	}

	int get(int index) {
		ListNode *p = virtual_head;
		if (index < 0) return -1;
		if (p->next == nullptr) return -1;
		for (int i = 0; i <= index; i++) {
			p = p->next;
			if (p->next == nullptr && i != index) return -1;
		}
		return p->val;
	}

	void addAtHead(int val) {
		virtual_head->next = new ListNode(val, virtual_head->next);
		size++;
	}

	void addAtTail(int val) {
		ListNode *p = virtual_head;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = new ListNode(val);
		size++;
	}

	void addAtIndex(int index, int val) {
		ListNode *p = virtual_head;
		if (index < 0) return;
		for (int i = 0; i < index; i++) {
			// 如果链表为空，且index大于0，则不加这个判断会出错
			if (p->next == nullptr) return;
			p = p->next;
			// 如果在遍历的过程中，没有在最后一个循环之前就遇到了空指针，说明index非法
			// 如果是最后一个循环，则说明需要插入到链表尾端
			if (p->next == nullptr && i != index - 1) return;
		}
		ListNode *tmp = p->next;
		p->next = new ListNode(val);
		p->next->next = tmp;
		size++;
	}

	void deleteAtIndex(int index) {
		ListNode *p = virtual_head;
		if (index < 0) return;
		// 循环结束后的指针将指向需要删除的那个节点的上一个节点
		for (int i = 0; i < index; i++) {
			p = p->next;
			// 因为循环结束后的指针p需要指向删除的节点的上一个节点
			// 如果p->next是空指针，说明index非法
			if (p->next == nullptr) return;
		}
		ListNode *tmp = p->next;
		p->next = p->next->next;
		delete tmp;
		size--;
	}

	/**
	 * 第24题 交换相邻节点
	 * @param head
	 * @return
	 */
	ListNode *swapPairs(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *head_proxy = head->next;
		ListNode *p = head;
		ListNode *left = nullptr, *right = nullptr;
		while (p != nullptr) {
			right = p->next;
			if (left != nullptr) {
				if (right == nullptr) {
					left->next = p;
					return head_proxy;
				} else {
					left->next = right;
				}
			}
			left = p;
			p = right->next;
			right->next = left;
			left->next = nullptr;
		}
		return head_proxy;
	}

	/**
	 *
	 * @param head
	 * @param n
	 * @return
	 */
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *fast = head, *slow = head;
		int cnt = 0;
		while (fast != nullptr) {
			fast = fast->next;
			if (cnt > n) {
				slow = slow->next;
			}
			cnt++;
		}
		ListNode *tmp;
		// cnt 记录了链表的长度，如果其与n相等，说明需要删除第一个
		// 删除第一个与删除其他的不同，所以需要特殊处理
		if (cnt == n && slow == head) {
			tmp = slow->next;
			delete slow;
			return tmp;
		} else {
			tmp = slow->next;
			slow->next = slow->next->next;
			delete tmp;
			return head;
		}
	}

	/** 160 相交链表，做法1 使用哈希表，存储两个链表的各个指针，然后对比
	 *
	 * @param headA
	 * @param headB
	 * @return
	 */
	ListNode *getIntersectionNode_hash(ListNode *headA, ListNode *headB) {
		unordered_set<ListNode *> set;
		ListNode *p = headA;
		while (p != nullptr) {
			set.insert(p);
			p = p->next;
		}
		p = headB;
		while (p != nullptr) {
			if (set.find(p) != set.end()) {
				return p;
			}
			p = p->next;
		}
		return nullptr;
	}

	/** 160 相交链表，做法2 双指针法 很妙
	 *
	 * @param headA
	 * @param headB
	 * @return
	 */
	ListNode *getIntersectionNode_dual_point(ListNode *headA, ListNode *headB) {
		ListNode *pA = headA, *pB = headB;
		if (headA == nullptr || headB == nullptr) return nullptr;
		while (1) {
			if (pA == pB) return pA;
			if (pA == nullptr) pA = headB;
			if (pB == nullptr) pB = headA;
			pA = pA->next;
			pB = pB->next;
		}
	}

	/**
	 * 检测链表中的环，使用哈希表
	 * @param head
	 * @return
	 */
	ListNode *detectCycle(ListNode *head) {
		unordered_set<ListNode *> set;
		ListNode *p = head;
		while (p != nullptr) {
			// 亦可使用set.count(p) 统计集合中 p出现的次数，出现次数只会是0-1
			if (set.find(p) != set.end()) {
				return p;
			} else {
				set.insert(p);
				p = p->next;
			}
		}
		return nullptr;
	}

	/**
	 * 检测链表中的环，使用双指针,主要思想为，快指针一次走两步，慢指针一次走一步，
	 * 最后快慢指针一定会在环中相遇，为啥呢，就是数学知识，快慢指针在环中相遇后，
	 * 就需要进一步的找到环的入口地址
	 * @param head
	 * @return
	 */
	ListNode *detectCycle_dual_pointer(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while(fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			// 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
			if (slow == fast) {
				ListNode* index1 = fast;
				ListNode* index2 = head;
				while (index1 != index2) {
					index1 = index1->next;
					index2 = index2->next;
				}
				return index2; // 返回环的入口
			}
		}
		return nullptr;
	}

	void print_list() {
		ListNode *p = virtual_head;
		while (p->next != nullptr) {
			cout << p->next->val << ' ';
			p = p->next;
		}
		cout << endl;
	}

	void print_list(ListNode *head) {
		ListNode *p = head;
		while (p != nullptr) {
			cout << p->val << ' ';
			p = p->next;
		}
		cout << endl;
	}

	ListNode *getVirtualHead() {
		return virtual_head;
	}

	ListNode *gettail() {
		ListNode *p = virtual_head;
		while (p->next != nullptr) {
			p = p->next;
		}
		return p;
	}

private:
	int size;
	ListNode *virtual_head;
};


int main() {
	MyLinkedList *ListA = new MyLinkedList();

	for (int i = 0; i < 7; i++) ListA->addAtTail(i + 1);
	ListA->gettail()->next = ListA->getVirtualHead()->next->next;

	cout << ListA->detectCycle_dual_pointer(ListA->getVirtualHead()->next)->val << endl;


}