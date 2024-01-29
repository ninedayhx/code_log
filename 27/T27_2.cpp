/**
* leetcode CT150 T27 移除元素 官方题解，双指针法，有点妙
 */
#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int p2 = 0;
	for(int p1 = 0; p1 < nums.size(); p1++)
	{
		if(nums[p1]!=val)
		{
			if(p1!=p2)
				nums[p2] = nums[p1];
			p2++;
		}
	}
	return p2;
}

int main() {
	vector<int> nums = {3,2,2,3};
	int val = 3;
	vector<int> nums1 = {0,1,2,2,3,0,4,2};
	int val1 = 2;
	cout<<removeElement(nums1, val1)<<endl;
	for (const auto &c : nums1) cout << c << " ";
	return 0;
}