/**
* Leetcode CT150 T26 删除有序数组的重复项 自己写的，非常傻逼的办法，没有学到什么东西
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		vector<int> tmp;
		int p1 = 0, p2 = 0, cnt = 0, len = nums.size();
		for (int i = 0; i < len; i++) {
			if (nums[p1] != nums[p2]) {
				p2 = p1;
			}
			if (p1 == p2) {
				tmp.push_back(nums[p1]);
				cnt++;
			}
			p1++;
		}
		for (int j = 0; j < cnt; j++) {
			nums[j] = tmp[j];
		}
		return cnt;
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