// tag:
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    bool isMax(vector<int> &height, int x)
    {
        if (x == 0)
        {
            return false;
        }
        if (x == height.size() - 1)
        {
            if (height[x] >= height[x - 1])
                return true;
            else
                return false;
        }
        if (height[x] > height[x - 1] && height[x] >= height[x + 1])
        {
            return true;
        }
        return false;
    }

public:
    /**
     * @brief 对于每一个点，分别向左向右找出该点的左右两边的最大值，
     *        然后利用最大值，求出当前点能存雨水的量
     * @param height
     * @return int
     */
    int trap_easy(vector<int> &height)
    {
        int res = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            int leftmax = *max_element(height.begin(), height.begin() + i);
            int rightmax = *max_element(height.begin() + i, height.end());
            res += (min(leftmax, rightmax) - height[i]) >= 0 ? min(leftmax, rightmax) - height[i] : 0;
        }
        return res;
    }
    /**
     * @brief 在直观的方法中，时间复杂度o(n2)，如果能提前找出每一个
     *        点的左右最大值，就能降低时间复杂度，所以先使用dp的方法，
     *        提前找出左右最大值
     * @param height
     * @return int
     */
    int trap_dp(vector<int> &height)
    {
        int res = 0;
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
            rightMax[n - i - 1] = max(rightMax[n - i], height[n - i - 1]);
        }
        for (int i = 0; i < n; ++i)
        {
            res += (min(leftMax[i], rightMax[i]) - height[i]) > 0 ? (min(leftMax[i], rightMax[i]) - height[i]) : 0;
        }
        return res;
    }
};

int main()
{
    // vector<int> rain = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> rain = {4, 2, 0, 3, 2, 5};
    Solution s;
    cout << s.trap_easy(rain) << endl;
    cout << s.trap_dp(rain) << endl;
}