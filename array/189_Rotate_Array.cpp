// tag:
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 方法1：队列模拟
 *
 * @param nums
 * @param k
 */
void rotate_queue(vector<int> &nums, int k)
{
    queue<int> q;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        q.emplace(nums[i]);
    }
    for (int i = 0; i < k; ++i)
    {
        q.emplace(q.front());
        q.pop();
    }
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        nums[i] = q.front();
        q.pop();
    }
}

/**
 * @brief 方法二：三次翻转
 *
 * @param nums
 * @param k
 */
void rotate_reverse(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    if (k == 0)
        return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

/**
 * @brief 方法三 环形替换
 *        环形替换时的循环次数是选择最大公约数，结束条件是是否回到起点
 *        求取最大公约数的api 是__gcd(a,b)
 *        辗转相除法求取最大公约数
 *        扩展：
 *             最小公倍数是 (a*b)/gcd(a,b)
 * @param nums
 * @param k
 */

/**
 * @brief 辗转相除法求取最大公约数
 *        x， y不区分大小
 * @param x
 * @param y
 * @return int
 */
int my_gcd(int x, int y)
{
    int z = y;
    while (x % y != 0)
    {
        // x比y小，取余 则 z = 小的数
        // 而后x=y 则自动x,y调整为一大一小
        z = x % y;
        x = y;
        y = z;
    }
    return;
}
/**
 * @brief 方法三：环形替换，注意，环形替换时的循环次数是选择最大公约数，
 *        结束条件是是否回到起点c++ api 有求取最大公约数的api 是__gcd(a,b)
 *
 * @param nums
 * @param k
 */
void rotate_(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    if (k == 0)
        return;
    for (int i = 0; i < __gcd(n, k); ++i)
    {
        int cur = nums[i], next = 0;
        for (int j = 0; j < n; ++j)
        {
            next = nums[(i + (j + 1) * k) % n];
            nums[(i + (j + 1) * k) % n] = cur;
            cur = next;
            if ((i + (j + 1) * k) % n == i)
                break;
        }
    }
}
int main()
{
}