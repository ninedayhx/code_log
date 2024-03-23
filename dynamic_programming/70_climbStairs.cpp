/**
 * 动态规划，爬楼梯，主要是是需要找出状态转移方程
 *
 */
#include <iostream>
#include <vector>

using namespace std;

int climbstairs(int n){
	if(n < 3) return n;
	int dp_n, dp_l, dp_ll;
	dp_ll = 1;
	dp_l = 2;
	for(int i=3; i<=n; i++){
		dp_n = dp_l+dp_ll;
		dp_ll = dp_l;
		dp_l = dp_n;
	}
	return dp_n;
}

int main(){
	int n;
	while(cin>>n) {
		cout<<climbstairs(n);
	}
}