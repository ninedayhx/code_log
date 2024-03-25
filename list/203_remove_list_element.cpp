#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {};

	ListNode(int x) : val(x), next(nullptr) {};

	ListNode(int x, ListNode *p) : val(x), next(p) {};
};

ListNode* removeElements(ListNode* head, int val) {
	ListNode* virtual_head = new ListNode();
	virtual_head->next = head;
	ListNode* pNode = virtual_head;
	while (pNode->next != nullptr) {
		if (pNode->next->val == val) {
			ListNode* tmp = pNode->next;
			// 既删除了，又切换道下一个节点了
			pNode->next = pNode->next->next;
			delete tmp;
		} else {
			pNode = pNode->next;
		}
	}
	// 被删除的节点需要进行delete,回收内存，防止内存泄露
	delete virtual_head;
	return head;
}

int main() {
	int n, tg;
	ListNode *head = new ListNode();
	ListNode *pNode;
	pNode = head;
	while (cin >> n) {
		pNode->val = n;
		if (cin.get() == '\n') break;
		pNode->next = new ListNode();
		pNode = pNode->next;
	}
	cin >> tg;

	pNode = removeElements(head, tg);
	while (pNode != nullptr) {
		cout << pNode->val << ' ';
		pNode = pNode->next;
	}
	cout << endl;
}
