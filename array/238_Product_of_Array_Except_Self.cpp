// tag: array 双指针
#include <bits/stdc++.h>

using namespace std;

// 要求 o(1)空间，以及o（n）时间，且不能用除法

// 下列方法不满足要求
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> except0;
    int prod = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            prod *= nums[i];
        }
        else
        {
            except0.emplace_back(i);
        }
    }
    vector<int> res(nums.size(), 0);
    if (except0.size() > 1)
    {
        return res;
    }
    else if (except0.size() == 1)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                res[i] = prod;
            }
        }
    }
    else
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            res[i] = prod / nums[i];
        }
    }
    return res;
}

// 双指针法 使用两个向量存储每一个元素的左右的成绩，最后相乘
vector<int> productExceptSelf_dualpoints(vector<int> &nums)
{
    int n = nums.size();
    vector<int> left(n + 1, 1), right(n + 1, 1);
    int l = 1, r = n - 2;
    while (l < n)
    {
        left[l] *= nums[l - 1] * left[l - 1];
        right[r] *= nums[r + 1] * right[r + 1];
        ++l;
        --r;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
    {
        ans[i] = left[i] * right[i];
    }
    return ans;
}

// 双指针法 空间优化版 很妙
vector<int> productExceptSelf_dualpoints(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);
    int l = 0, r = n - 1;
    int lp = 1, rp = 1;
    while (l < n && r >= 0)
    {
        ans[l] *= lp;
        ans[r] *= rp;
        lp *= nums[l];
        rp *= nums[r];
        ++l;
        --r;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    auto res = productExceptSelf(nums);
    for (int &i : res)
    {
        cout << i << ' ';
    }
    cout << endl;
}