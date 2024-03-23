/**
 * leetcode CT150 T80 删除数组的重复项 Ⅱ 是第26题的衍生
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int> &nums) {
		int n = nums.size();
		if (n <= 2) {
			return n;
		}
		int slow = 2, fast = 2;
		while (fast < n) {
			if (nums[slow - 2] != nums[fast]) {
				nums[slow] = nums[fast];
				++slow;
			}
			++fast;
		}
		return slow;
	}
};

int main() {
	vector<int> n = {1, 1, 1, 2, 2, 3};
	Solution solve;
	cout << solve.removeDuplicates(n) << '\n';
	for (int i = 0; i < n.size(); i++) {
		cout << n[i] << '\n';
	}
	return 0;
}