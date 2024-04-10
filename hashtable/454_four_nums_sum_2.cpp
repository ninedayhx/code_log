#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 暴力解法，会超时
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
	int tag = 0, cnt = 0;
	for (const auto &i:nums1) {
		for (const auto &j:nums2) {
			for (const auto &k:nums3) {
				for (const auto &l:nums4) {
					if(i+j+k+l==tag){
						cnt++;
					}
				}
			}
		}
	}
	return cnt;
}

// 先分再加
int fourSumCount_hash(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
	int tag = 0, cnt = 0;
	unordered_map<int, int> table_12, table_34;

	for (const auto &i:nums1) {
		for (const auto &j:nums2) {
			table_12[i+j]++;
		}
	}

	for (const auto &i:nums3) {
		for (const auto &j:nums4) {
			if(table_12.find(-(i+j))!=table_12.end()){
				cnt += table_12[-(i+j)];
			}
		}
	}

	return cnt;
}


int main() {
	int n;
	vector<int> nums1, nums2, nums3, nums4;
	while (1) {
		while (cin >> n) {
			nums1.push_back(n);
			if (cin.get() == '\n') break;
		}
		while (cin >> n) {
			nums2.push_back(n);
			if (cin.get() == '\n') break;
		}
		while (cin >> n) {
			nums3.push_back(n);
			if (cin.get() == '\n') break;
		}
		while (cin >> n) {
			nums4.push_back(n);
			if (cin.get() == '\n') break;
		}
		cout << fourSumCount(nums1, nums2, nums3, nums4) << endl;
		cout << fourSumCount_hash(nums1, nums2, nums3, nums4) << endl;
	}
}