// leetcode 167 两数之和2
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        return {};
    }
};

int main()
{
    Solution solver;
    vector<int> num;
    int n;
    while (cin >> n)
    {
        num.emplace_back(n);
        if (cin.get() == '\n')
            break;
    }
    cin >> n;
    auto res = solver.twoSum(num, n);
}