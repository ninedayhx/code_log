// tag:
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    // 每一次循环中，都进行了一次new 开销很大
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *root = new ListNode();
        ListNode *l1 = list1, *l2 = list2, *p = root;
        while (l1 || l2)
        {
            if (!l1)
            {
                p->next = l2;
                break;
            }
            if (!l2)
            {
                p->next = l1;
                break;
            }
            if (l1->val <= l2->val)
            {
                p->next = new ListNode(l1->val);
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                p->next = new ListNode(l2->val);
                p = p->next;
                l2 = l2->next;
            }
        }
        return root->next;
    }

    // 直接把指针覆盖过去了，缺点是会改变原链表
    ListNode *mergeTwoLists2(ListNode *list1, ListNode *list2)
    {
        ListNode *root = new ListNode();
        ListNode *l1 = list1, *l2 = list2, *p = root;
        while (l1 || l2)
        {
            if (l1->val <= l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
            if (!l1)
            {
                p->next = l2;
                break;
            }
            if (!l2)
            {
                p->next = l1;
                break;
            }
        }
        return root->next;
    }
};

int main()
{
}