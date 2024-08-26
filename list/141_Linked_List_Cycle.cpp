// tag: list 找链表中的环
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
    bool hasCycle_hash(ListNode *head)
    {
        unordered_set<ListNode *> visited;
        while (head)
        {
            if (visited.find(head) != visited.end())
            {
                return true;
            }
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
    bool hasCycle1(ListNode *head)
    {
        if (!head || !head->next)
            return false;
        // 如果有环，fast初始为head还是初始为next，最后slow和fast一定会相遇
        // 这里使用next是为了满足while的循环条件，
        // 如果想使用head,就使用do while 因为do while是先执行循环，再判定条件
        ListNode *fast = head, *slow = head;
        do
        {
            // 如果没有环， fast指针一定的是先到达末尾的，所以
            // 使用fast指针作为退出的判断条件
            if (!fast || !fast->next)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        } while (fast != slow);
        return true;
    }
    bool hasCycle2(ListNode *head)
    {
        if (!head || !head->next)
            return false;
        // 如果有环，fast初始为head还是初始为next，最后slow和fast一定会相遇
        // 这里使用next是为了满足while的循环条件，
        // 如果想使用head,就使用do while 因为do while是先执行循环，再判定条件
        ListNode *fast = head->next, *slow = head;
        while (fast != slow)
        {
            // 如果没有环， fast指针一定的是先到达末尾的，所以
            // 使用fast指针作为退出的判断条件
            if (!fast || !fast->next)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

int main()
{
}