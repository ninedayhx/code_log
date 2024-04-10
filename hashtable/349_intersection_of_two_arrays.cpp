#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> myintersection(vector<int> &nums1, vector<int> &nums2) {
	unordered_set<int> visit1, visit2;
	vector<int> res;
	for (const auto &i: nums1) {
		visit1.insert(i);
	}
	for (const auto &i: nums2) {
		visit2.insert(i);
	}
	for (const auto &i: visit1) {
		if (visit2.count(i)) {
			res.push_back(i);
		}
	}
	return res;
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
	// 可以通过这种方式进行初始化，这等于遍历一次
	unordered_set<int> visit1(nums1.begin(), nums1.end());
	// 如果用vector去存储，则会存入多个相同元素，所以应该用set去存
	//vector<int> res;
	unordered_set<int> res;
	// 再遍历一次nums2，与set内部元素进行对比
	for (const auto &i: nums2) {
		if(visit1.count(i)) res.insert(i);
	}
	return vector<int>(res.begin(), res.end());
}

int main() {
	int a, b;
	vector<int> nums1, nums2, common;
	while (1) {
		while (cin >> a) {
			nums1.push_back(a);
			if (cin.get() == '\n') break;
		}
		while (cin >> b) {
			nums2.push_back(b);
			if (cin.get() == '\n') break;
		}
		common = intersection(nums1, nums2);
		for(const auto &i:common){
			cout<<i<<' ';
		}
		cout<<endl;
	}
}
