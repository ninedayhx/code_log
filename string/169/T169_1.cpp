/**
 * Leetcode CT150 T169 多数元素 自己写的暴力解法 自己写的暴力解法 复杂度o(n^2)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int> &nums) {
		int  len = nums.size(), cnt=0;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (nums[i] == nums[j]) { cnt++; }
			}
			if (cnt > (len / 2)) {
				return nums[i];
			}
			cnt = 0;
		}
	}
};

int main() {
	vector<int> nums = {2, 1, 1, 1, 1, 2, 2};
	Solution solver;
	cout << solver.majorityElement(nums);
	return 0;
}