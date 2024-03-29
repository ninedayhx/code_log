#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 暴力解法
vector<int> sortedSquares1(vector<int>& nums) {
	for(auto &i: nums){
		i = i*i;
	}
	sort(nums.begin(), nums.end());
	return nums;
}

// 双指针解法
vector<int> sortedSquares(vector<int>& nums) {
	int first = 0, last = nums.size()-1, p = nums.size()-1;
	int res_f, res_l;
	vector<int> res(nums.size());
	while(p>=0){
		res_f = nums[first]*nums[first];
		res_l = nums[last]*nums[last];
		if(res_f > res_l) {
			res[p] = res_f;
			first ++;
			p--;
		}else if(res_f <= res_l){
			res[p] = res_l;
			last--;
			p--;
		}
	}
	return res;
}

int main(){
	int n;
	vector<int> nums,res;
	while(cin>>n){
		nums.push_back(n);
		if(cin.get()=='\n') break;
	}
	res = sortedSquares(nums);
	for(const auto & i:res){
		cout<<i<<' ';
	}
	cout<<endl;
}