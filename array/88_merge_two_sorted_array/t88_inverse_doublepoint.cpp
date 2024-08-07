/**
 * leetcode 88 合并两个有序数组 逆向双指针法
 */

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	int p1 = 0, p2 = 0;
	while (p1 < m || p2 < n) {
		if (p1 == m) {
			nums1.at(n + m - 1 - p1 - p2) = nums2.at(n - p2 - 1);
			p2++;
		} else if (p2 == n) {
			nums1.at(n + m - 1 - p1 - p2) = nums1.at(m - p1 - 1);
			p1++;
		} else if (nums1.at(m - p1 - 1) <= nums2.at(n - p2 - 1)) {
			nums1.at(n + m - 1 - p1 - p2) = nums2.at(n - p2 - 1);
			p2++;
		} else {
			nums1.at(n + m - 1 - p1 - p2) = nums1.at(m - p1 - 1);
			p1++;
		}
	}
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