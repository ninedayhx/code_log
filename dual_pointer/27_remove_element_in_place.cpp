#include <iostream>
#include <vector>

using namespace std;

// 双指针法移除元素，此方法不会改变数组中元素的相对位置
int removeElement(vector<int> &nums, int val) {
	int fast = 0, slow = 0;
	while(fast<nums.size()){
		if(nums[fast] != val){
			nums[slow++] = nums[fast];
		}
		fast++;
	}
	nums.resize(slow);
	return slow;
}

int main() {
	vector<int> nums;
	int val, n;
	while (cin >> n) {
		nums.push_back(n);
		if(cin.get()=='\n') break;
	}
	for(auto & i:nums){
		cout<<i<<' ';
	}
	cin >> val;
	cout << removeElement(nums, val)<<endl;
	for(auto & i:nums){
		cout<<i<<' ';
	}
	cout<<endl;
}
