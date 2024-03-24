#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> v(n, vector<int>(n));
	if (n == 1) {
		v[0][0] = 1;
		return v;
	}
	int p = 1;
	int circle = 0;
	for (int i = n; i > 0; i -= 2) {
		if(i==1) {
			v[n/2][n/2] = p;
		}
		for (int j = 0; j < i - 1; j++) {
			v[circle][j + circle] = p;
			p++;
		}
		for (int j = 0; j < i - 1; j++) {
			v[j + circle][n - 1 - circle] = p;
			p++;
		}
		for (int j = 0; j < i - 1; j++) {
			v[n - 1 - circle][n - 1 - circle - j] = p;
			p++;
		}
		for (int j = 0; j < i - 1; j++) {
			v[n - 1 - circle - j][circle] = p;
			p++;
		}
		circle++;
	}
	return v;
}


int main() {
	int n;
	vector<vector<int>> v;
	while (cin >> n) {
		v = generateMatrix(n);
		for (auto i: v) {
			for (auto j: i)
				cout << j<<" ";
			cout << endl;
		}
	}
}
