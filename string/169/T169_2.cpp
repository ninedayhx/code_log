/**
 * Leetcode CT150 T169 多数元素 哈希表
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int> &nums) {
		unordered_map<int, int> counts;
		int majority = 0, n = nums.size();
		for (int num : nums) {
			++counts[num];  // 统计数字num出现的次数
			//cout<<"n="<<num<<","<<counts[num]<<'\n';
			if (counts[num] > n / 2) {
				return num;
			}
		}
		return -1;
	}
};

int main() {
	vector<int> nums = {2, 1, 1, 1, 1, 2, 2};
	Solution solver;
	cout << solver.majorityElement(nums);
	return 0;
}