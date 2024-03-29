#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

// 暴力解法 会超时
int minSubArrayLen1(int target, vector<int> &nums) {
	int len = nums.size();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i; j++) {
			for (int k = 0; k <= i; k++) {
				sum += nums[j + k];
			}
			if (sum >= target) return i + 1;
			sum = 0;
		}
	}
	return -1;
}

// 自己写的滑动窗口法，还是超时了
int minSubArrayLen2(int target, vector<int> &nums) {
	int left = 0, right = 0;
	int len = nums.size();
	int sum = 0, res = INT32_MAX;
	while (1) {
		for (int i = left; i <= right; i++) {
			sum += nums[i];
		}
		if (sum >= target) {
			// 注意此处要时刻维护min值为最小，而且要使用标志位使得min能初始化
			int tmp = right - left + 1;
			res = min(res, tmp);
			if (left < right) left++;
			else break;
		} else if (sum < target) {
			if (right == len - 1) break;
			else right++;
		}
		sum = 0;
	}
	if (res == INT32_MAX) return 0;
	else return res;
}

int minSubArrayLen(int target, vector<int> &nums) {
	int n = nums.size();
	if (n == 0) return 0;
	int res = INT32_MAX;
	int left = 0, right = 0, sum = 0;
	while (right < n) {
		sum += nums[right];
		while (sum >= target) {
			res = min(res, right - left + 1);
			sum -= nums[left];
			left++; // 滑动窗口
		}
		right++;
	}
	// 如果res==INT32_MAX，结果就是0.如果不是，就是正常值
	return (res == INT32_MAX) ? 0:res;

}

int main() {
	int target, n;
	vector<int> nums;
	cin >> target;

	while (cin >> n) {
		nums.push_back(n);
		if (cin.get() == '\n') break;
	}
	cout << minSubArrayLen1(target, nums) << endl;
	cout << minSubArrayLen(target, nums) << endl;


}