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
		ListNode * pA = headA, *pB = headB;
		if(headA== nullptr|| headB == nullptr) return nullptr;
		while(1){
			if(pA == pB) return pA;
			if(pA == nullptr) pA = headB;
			if(pB == nullptr) pB = headA;
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
		ListNode * p = head;
		while(p!= nullptr){
			// 亦可使用set.count(p) 统计集合中 p出现的次数，出现次数只会是0-1
			if(set.find(p)!=set.end()){
				return p;
			}else {
				set.insert(p);
				p = p->next;
			}
		}
		return nullptr;
	}

	ListNode *detectCycle_doublepoints(ListNode *head)
	{
		if (!head || !head->next)
			return nullptr;
		ListNode *fast = head->next, *slow = head;
		// 假设有环，起点到环的入口长度为a，fast指针走的比slow快，
		// slow到达环的入口时，fast已经在环内了, fast走的比slow快
		// 进入环后，fast一定能追上slow
		while (fast != slow)
		{
			if (!fast || !fast->next)
			{
				return nullptr;
			}
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode *node = head;
		// 起点到环的入口长度为a
		// 假设当fast追上 slow 时，slow从环的入口到相遇点走了b
		// 相遇点到入口长度为c
		// fast在环内走了n圈+b然后与slow相遇，也就是
		// fast所走路程为 a + n*(b+c) +b
		// slow所走的所有路程为 a+b
		// fast是slow的两倍速度， 所以
		// 2*(a+b) = a + n*（b+c）+b
		// a = (n-1)b +n*c = (n-1)*(b+c) +c
		// 也就是说，如果有一个指针从起点出发，到环的入口，slow指针也从相遇点出发，
		// 最后会在入口相遇，指针走a步，而slow走n-1圈加c步，刚好到入口
		// 注意如果fast指针不从head出发，则slow会慢一步，不会像之前所说的那样在入口相遇
		while (node == slow->next)
		{
			node = node->next;
			slow = slow->next;
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

	cout<<ListA->detectCycle(ListA->getVirtualHead()->next)->val<<endl;



}