// leetcode 167 两数之和2
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int first = 0, last = numbers.size() - 1;
        while (first != last)
        {
            int sum = numbers[first] + numbers[last];
            if (sum > target)
            {
                --last;
            }
            else if (sum < target)
            {
                ++first;
            }
            else
            {
                return {first + 1, last + 1};
            }
        }
        return {-1, -1};
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
    cout << res[0] << "," << res[1] << endl;
}