// tag: list
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *node = new ListNode(0);
    ListNode *root = node;
    // 进位值
    int shift = 0;
    while (l1 || l2)
    {
        int a = 0, b = 0;
        if (l1)
        {
            a = l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            b = l2->val;
            l2 = l2->next;
        }
        // 必须要在此处加上进位值，否则当 a+b = 9 的时候，shift =1 时将会出错
        int sum = a + b + shift;
        node->val = sum % 10;
        shift = sum / 10;
        // 当有进位时，需要加后续节点
        // l1 l2 有时也需要加
        if (shift > 0 || l1 || l2)
        {
            node->next = new ListNode(shift);
            node = node->next;
        }
    }
    return root;
}

// ListNode *createList(vector<int> v)
// {
//     ListNode *node = nullptr;
//     ListNode *root = nullptr;
//     static int flag = 0;
//     for (auto &i : v)
//     {
//         flag = 1;

//         root = new ListNode(i);
//         if (flag == 0)
//         {
//         }
//         root = root->next;
//     }
// }

int main()
{
    // vector<int> v1;
    // vector<int> v2;
    // while (1)
    // {
    //     int x;
    //     cin >> x;
    //     v1.push_back(x);
    //     if (cin.get() == '\n')
    //         break;
    // }
    // while (1)
    // {
    //     int x;
    //     cin >> x;
    //     v2.push_back(x);
    //     if (cin.get() == '\n')
    //         break;
    // }

    ListNode *n1 = new ListNode(9);
    n1->next = new ListNode(9);
    n1->next->next = new ListNode(9);

    ListNode *n2 = new ListNode(9);
    auto res = addTwoNumbers(n1, n2);
    while (res)
    {
        cout << res->val << ' ';
        res = res->next;
    }
    cout << endl;
}