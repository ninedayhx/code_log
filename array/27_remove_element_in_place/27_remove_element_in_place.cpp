#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val) {
	int n = nums.size();
	int tmp = 0;
	int cnt = 0;
	for (auto i: nums) {
		if (i == val) cnt++;
	}
	for (int i = 0; i < n; i++) {
		if (nums[i] == val) {
			for (int j = i + 1; j < n; j++) {
				if (nums[j] != val) {
					tmp = nums[i];
					nums[i] = nums[j];
					nums[j] = tmp;
					break;
				}
			}
		}
	}
	return n-cnt;
}

int main() {
	vector<int> nums;
	int val;
	int n;
	while (cin >> n) {
		nums.push_back(n);
		if(cin.get()=='\n') break;
	}
	cin >> val;
	cout << removeElement(nums, val)<<endl;
	for(auto & i:nums){
		cout<<i<<' ';
	}
}
