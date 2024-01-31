/**
* Leetcode CT150 T26 删除有序数组的重复项
 * 利用了有序数组的特性
 * 快慢指针，通过快指针和快指针前一个是否相同判断是否需要交换
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int p1 = 1, p2 = 1, len = nums.size();
		if (len == 0) {
			return 0;
		}
		while (p1 < len) {
			// 因为是有序数组，所以通过判断前一个数与当前数相等，来判断是否需要交换
			// 快指针访问过的位置都是可以交换的位置，所以慢指针只需要访问不重复元素的数字的位置即可
			// 所以最后慢指针的位置即为不重复元素的个数
			if (nums[p1] != nums[p1 - 1]) {
				nums[p2] = nums[p1];
				p2++;
			}
			p1++;
		}
		return p2;
	}
};

int main()
{
	vector<int> n = {0, 1, 1, 1, 2, 2, 3, 3, 4};
	Solution solve;
	cout << solve.removeDuplicates(n) << '\n';
	for (int i = 0; i < n.size(); i++) {
		cout << n[i] << '\n';
	}
	return 0;
}