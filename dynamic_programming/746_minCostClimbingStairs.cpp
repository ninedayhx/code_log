/**
 * 动态规划，最小费爬楼梯
 *
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 会陷入局部最优，考虑的只是当前步cost最优
int minCostClimbingStairs1(vector<int> vec) {
	int len = vec.size();
	int p = 0, min=0;
	if(vec[len-1]>=vec[len-2]){
		min+=vec[len-2];
		p=len-2;
	}else  {
		min += vec[len-1];
		p=len-1;
	}
	while (!(p == 0 || p == 1)) {
		if(vec[p-1]>=vec[p-2]){
			min+=vec[p-2];
			p=p-2;
		}else  {
			min += vec[p-1];
			p=p-1;
		}
	}
	return min;
}


// 全局最优
int minCostClimbingStairs(vector<int> cost) {
	int dpn,dp2,dp1;
	dp1 = 0;
	dp2 = 0;
	for(int i=2;i<=cost.size();i++)
	{
		dpn = min(dp1+cost[i-2], dp2+cost[i-1]);
		dp2 = dp1;
		dp1 = dpn;
	}
	return dpn;
}



int main() {
	vector<int> cost;
	int n;
	string s;
	while (cin >> n) {
		cost.push_back(n);
		if (cin.get() == '\n') {
			break;
		}
	}
	cout << minCostClimbingStairs(cost);
}