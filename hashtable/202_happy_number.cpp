#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdint>

using namespace std;

// 这样做肯定会超时的
bool myisHappy(int n) {
	int nums = n;
	while (nums<INT32_MAX) {
		vector<int> res;
		while (nums != 0) {
			res.push_back(nums%10);
			nums /= 10;
		}
		nums = 0;
		for(const auto &i:res){
			nums+=i*i;
		}
		if(nums == 1) return true;
	}
	return  false;
}

// 这道题主要是要知道，一个数按快乐数的方法进行计算，只有两种结果
// 1. 回归到1，在1中无限循环
// 2.在另外一个了链路中不断循环，所以只需要检测是否无限循环即可
// 即检测计算的一个数是否出现过，是否出现过，就使用set
bool isHappy(int n) {
	int nums = n, next = 0;
	unordered_set<int> res_list;
	while (nums<INT32_MAX) {
		while (nums) {
			int x = nums % 10;
			next += x*x;
			nums /= 10;
		}
		if(next==1) return true;
		else{
			if(res_list.count(next)) return false;
			res_list.insert(next);
			nums = next;
			next = 0;
		}
	}
	return false;
}

int main() {
	int n;
	while (cin >> n) {
		cout << isHappy(n) << endl;
	}
}