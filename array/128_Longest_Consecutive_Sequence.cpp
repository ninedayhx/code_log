// tag:
#include <bits/stdc++.h>

using namespace std;

int longestConsecutive_regular(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int maxlen = 0, len = 0;
    int tmp = INT32_MAX;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] - 1 == tmp)
            ++len;
        else if (nums[i] == tmp)
        {
            // 处理重复元素
        }
        else
        {
            maxlen = max(maxlen, len + 1);
            len = 0;
        }
        if (i == nums.size() - 1)
        {
            maxlen = max(maxlen, len + 1);
        }
        tmp = nums[i];
    }
    return maxlen;
}

void qsort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int base = arr[l + rand() % (r - l + 1)];
        int first = l;
        int last = r;
        int i = l;
        while (i <= last)
        {
            if (arr[i] == base)
            {
                ++i;
            }
            else if (arr[i] < base)
            {
                swap(arr[i++], arr[first++]);
            }
            else
            {
                swap(arr[i], arr[last--]);
            }
        }
        int part = first;
        qsort(arr, l, part - 1);
        qsort(arr, part + 1, r);
    }
}

int main()
{
    vector<int> n = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    qsort(n, 0, n.size() - 1);
    for (auto &i : n)
    {
        cout << i << ' ';
    }
    cout << endl;
    cout << longestConsecutive_regular(n);
}