/**
 * Leetcode CT150 T169 多数元素 按照题意，可以先对数组进行排序
 * 然后通过多数元素将处于数组中间，如下使用sort进行快排，取中位即为多数元素
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int> &nums) {
		int n = nums.size();
		std::sort(nums.begin(), nums.end());
		return nums[n/2];
	}
};

int main() {
	vector<int> nums = {2, 1, 1, 1, 1, 2, 2};
	Solution solver;
	cout << solver.majorityElement(nums);
	return 0;
}