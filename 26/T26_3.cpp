/**
* Leetcode CT150 T26 删除有序数组的重复项
 * 使用c++的api unique ，该算法需要使用algorithm头文件
 * unique 去除有序数组或者向量中的重复元素，使用前需要对无序数组进行排序
 * 此算法似乎就是使用T26_2中快慢指针算法
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
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