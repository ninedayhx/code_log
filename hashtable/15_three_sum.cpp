#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 暴力解法 会超时
vector<vector<int>> mythreeSum(vector<int> &nums) {
	sort(nums.begin(), nums.end());
	int flag = 0;
	vector<vector<int>> res;
	int len = nums.size();
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			for (int k = j + 1; k < len; k++) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					vector<int> tmp;
					tmp.push_back(nums[i]);
					tmp.push_back(nums[j]);
					tmp.push_back(nums[k]);
					for (const auto &v: res) {
						int cnt=0;
						for (int l = 0; l < 3; l++) {
							if(tmp[l]==v[l]){
								cnt++;
							}
						}
						if(cnt==3) {
							flag = 1;
							break;
						}
					}
					if(res.empty()){
						res.push_back(tmp);
					}else {
						if (flag == 0) {
							res.push_back(tmp);
						} else {
							flag = 0;
						}
					}
				}
			}
		}
	}
	return res;
}

// 双指针法，没有理解这些东西
vector<vector<int>> threeSum(vector<int>& nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	// 枚举 a
	for (int first = 0; first < n; ++first) {
		// 需要和上一次枚举的数不相同
		if (first > 0 && nums[first] == nums[first - 1]) {
			continue;
		}
		// c 对应的指针初始指向数组的最右端
		int third = n - 1;
		int target = -nums[first];
		// 枚举 b
		for (int second = first + 1; second < n; ++second) {
			// 需要和上一次枚举的数不相同
			if (second > first + 1 && nums[second] == nums[second - 1]) {
				continue;
			}
			// 需要保证 b 的指针在 c 的指针的左侧
			while (second < third && nums[second] + nums[third] > target) {
				--third;
			}
			// 如果指针重合，随着 b 后续的增加
			// 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
			if (second == third) {
				break;
			}
			if (nums[second] + nums[third] == target) {
				ans.push_back({nums[first], nums[second], nums[third]});
			}
		}
	}
	return ans;
}



int main() {
	int n;
	vector<vector<int>> res;
	while(1){
		vector<int> input;
		while(cin>>n){
			input.push_back(n);
			if(cin.get()=='\n') break;
		}
		res = threeSum(input);
		for(const auto & v:res){
			for(const auto & i:v){
				cout<<i<<' ';
			}
			cout<<endl;
		}
	}
}
