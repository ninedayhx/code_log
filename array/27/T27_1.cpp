
/**
* leetcode CT150 T27 移除元素 自己写的解法，完全是靠api实现的
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int cnt = 0, len = nums.size();
	for(auto it = nums.begin(); it!=nums.end();)
	{
		if(*it == val)
		{
			it = nums.erase(it);
			cnt++;
		}
		else
		{
			it++;
		}
	}
	return len - cnt;
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