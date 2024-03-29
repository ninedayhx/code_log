#include <iostream>

using namespace std;


class MyLinkedList {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr){};
		ListNode(int x) : val(x), next(nullptr){};
		ListNode(int x, ListNode* ptr) : val(x), next(ptr){};
	};
	MyLinkedList() {
		virtual_head = new ListNode();
		size = 0;
	}

	int get(int index) {
		ListNode* p = virtual_head;
		for (int i = 0; i <= index; i++) {
			if (p->next == nullptr) {
				if(i==index) break;
				else return -1;
			}
			p = p->next;
		}
		return p->val;
	}
	void addAtHead(int val) {
		virtual_head->next = new ListNode(val, virtual_head->next);
	}

	void addAtTail(int val) {
		ListNode* p = virtual_head;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = new ListNode(val);
	}

	void addAtIndex(int index, int val) {
		ListNode* p = virtual_head;
		for (int i = 0; i < index; i++) {
			if (p->next->next == nullptr) {
				if (i == index - 1) {
					p->next = new ListNode(val);
					return;
				} else {
					return;
				}
			}
			p = p->next;
		}
		ListNode* tmp = p->next;
		p->next = new ListNode(val);
		p->next->next = tmp;
	}

	void deleteAtIndex(int index) {
		ListNode* p = virtual_head;
		for (int i = 0; i < index; i++) {
			if (p->next->next == nullptr) {
					return;
			}
			p = p->next;
		}
		ListNode* tmp = p->next;
		p->next = p->next->next;
		delete tmp;
	}
	void print_list(){
		ListNode * p = virtual_head;
		while(p->next!= nullptr){
			cout<<p->next->val<<' ';
			p = p->next;
		}
		cout<<endl;
	}
private:
	int size;
	ListNode * virtual_head;
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

int main(){
	MyLinkedList * obj =  new MyLinkedList();
	/// ------------
//	obj->addAtHead(7);
//	obj->print_list();
//	obj->addAtHead(2);
//	obj->print_list();
//	obj->addAtHead(1);
//	obj->print_list();
//	obj->addAtIndex(3,0);
//	obj->print_list();
//	obj->deleteAtIndex(2);
//	obj->print_list();
//	obj->addAtHead(6);
//	obj->print_list();
//	obj->addAtTail(4);
//	obj->print_list();
//	cout<<obj->get(4)<<endl;
//	obj->addAtHead(4);
//	obj->print_list();
//	obj->addAtIndex(5,0);
//	obj->print_list();
//	obj->addAtHead(6);
//	obj->print_list();
// ------------
//	obj->addAtHead(2);
//	obj->print_list();
//	obj->deleteAtIndex(1);
//	obj->print_list();
//	obj->addAtHead(2);
//	obj->print_list();
//	obj->addAtHead(7);
//	obj->print_list();
//	obj->addAtHead(3);
//	obj->print_list();
//	obj->addAtHead(2);
//	obj->print_list();
//	obj->addAtHead(5);
//	obj->print_list();
//	obj->addAtTail(5);
//	obj->print_list();
//	cout<<obj->get(5)<<endl;
//	obj->deleteAtIndex(6);
//	obj->print_list();
//	obj->deleteAtIndex(4);
//	obj->print_list();
// -------------
obj->addAtHead(4);
obj->print_list();
cout<<obj->get(1);
}