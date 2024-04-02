#include <iostream>

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

	void print_list() {
		ListNode *p = virtual_head;
		while (p->next != nullptr) {
			cout << p->next->val << ' ';
			p = p->next;
		}
		cout << endl;
	}

	void print_list(ListNode* head) {
		ListNode *p = head;
		while (p != nullptr) {
			cout << p->val << ' ';
			p = p->next;
		}
		cout << endl;
	}

	ListNode *reverseList(ListNode *head) {
		ListNode *p = head;
		ListNode *ph = head, *pp = nullptr, *ppp = nullptr;
		while(head != nullptr){ // 注意加上以上判断条件，使得当输入空链表时能够返回正确结果
			pp = p->next;
			if(pp== nullptr)
			{
				// 更改虚拟头节点位置
				virtual_head->next = ph;
				return ph;
			}
			ppp = p->next->next;
			pp->next = ph;
			p->next = ppp;
			ph = pp;
		}
		virtual_head->next = ph;
		return head;
	}

	ListNode * getVirtualHead(){
		return virtual_head;
	}


private:
	int size;
	ListNode *virtual_head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
	MyLinkedList *obj = new MyLinkedList();
	for (int i = 1; i < 6; i++) {
		obj->addAtTail(i);
	}
	obj->print_list();
	obj->print_list(obj->reverseList(obj->getVirtualHead()->next));
	obj->print_list();
}