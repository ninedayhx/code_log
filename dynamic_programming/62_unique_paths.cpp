#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// 递归会导致计算时间爆炸长，不能使用递归
int uniquePaths_recursion(int m, int n) {

	if (m < 1) return 0;
	if (n < 1) return 0;
	// 在边界处 路径均为1
	if (m == 1) return 1;
	if (n == 1) return 1;
	return uniquePaths_recursion(m - 1, n) + uniquePaths_recursion(m, n - 1);
}

// 递归会导致计算时间爆炸长，不能使用递归
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n));
	for(int i=0;i<m;i++) dp[i][0] = 1;
	for(int i=0;i<n;i++) dp[0][i] = 1;
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[m-1][n-1];
}


int main() {
	int m, n;
	while (cin >> m >> n) {
		//cout<<m<<' '<<n<<endl;
		cout << uniquePaths(m, n) << endl;
		cout<< uniquePaths_recursion(m,n)<<endl;
	}
	return 0;
}
