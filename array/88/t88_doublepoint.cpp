/**
* leetcode 88 合并两个有序数组 双指针法
 * 注意 并列if 和 else if 的区别，并列if 每一个if条件都会判断，else if 只会按循序判断，并且只进入第一个符合条件的判断中
*/
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

	vector<int> ntmp;

	int p = 0, p1 = 0, p2 = 0;

	while (p1 < m || p2 < n) {
		if (p1 == m) {
			ntmp.push_back(nums2.at(p2++));
		} else if (p2 == n) {
			ntmp.push_back(nums1.at(p1++));
		} else if (nums1.at(p1) <= nums2.at(p2)) {
			ntmp.push_back(nums1.at(p1));
			p1++;
		} else {
			ntmp.push_back(nums2.at(p2));
			p2++;
		}
		//		不可行
		//		if(p1==m)
		//		{
		//			ntmp.push_back(nums2.at(p2++));
		//		}
		//		if(p2==n)
		//		{
		//			ntmp.push_back(nums1.at(p1++));
		//		}
		//		if(nums1.at(p1)<=nums2.at(p2))
		//		{
		//			ntmp.push_back(nums1.at(p1));
		//			p1++;
		//		}else
		//		{
		//			ntmp.push_back(nums2.at(p2));
		//			p2++;
		//		}
	}
	nums1 = ntmp;
}


int main() {

	vector<int> n1 = {1, 2, 3, 0, 0, 0}, n2 = {4, 5, 6};
	int n = 3, m = 3;
	merge(n1, m, n2, n);
	for (int k = 0; k < n + m; k++) {
		cout << n1.at(k) << endl;
	}

	return 0;
};