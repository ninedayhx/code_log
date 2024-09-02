// tag: quick_sort dual_point skill
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 单指针，先把0放到前面，再把1放在0后面，
 *        自然就完成了排序
 * @param nums
 */
void sortColors_1p(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 0)
        {
            swap(nums[i], nums[cnt]);
            ++cnt;
        }
    }
    for (int i = cnt; i < nums.size(); ++i)
    {
        if (nums[i] == 1)
        {
            swap(nums[i], nums[cnt]);
            ++cnt;
        }
    }
}

/**
 * @brief 双指针版，同时把 0 放在最前面和把2放在最后面，
 *
 * @param nums
 */
void sortColors_2p(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    for (int i = 0; i < right; ++i)
    {
        while (nums[i] == 2)
        {
            swap(nums[i], nums[right]);
            --right;
        }
        if (nums[i] == 0)
        {
            swap(nums[i], nums[left]);
            ++left;
        }
    }
}

int main()
{
    vector<int> nums;
    while (1)
    {
        int x;
        cin >> x;
        nums.emplace_back(x);
        if (cin.get() == '\n')
            break;
    }
    sortColors_2p(nums);
    for (auto &i : nums)
    {
        cout << i << ' ';
    }
    cout << endl;
}