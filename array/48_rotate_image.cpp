// tag : array 模拟
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
	void swap4num(int &a, int &b, int &c, int &d)
	{
		int tmp;
		tmp = a;
		a = d;
		d = c;
		c = b;
		b = tmp;
	}
	void rotate(vector<vector<int>> &matrix)
	{
		// 模拟
		int n = matrix.size();
		int circ = n / 2 + n % 2;
		cout << circ << endl;
		for (int i = 0; i < circ; i++)
		{
			for (int j = i; j < n - i - 1; j++)
			{
				swap4num(matrix[i][j],				   // 1 1
						 matrix[j][n - 1 - i],		   // 1 2
						 matrix[n - 1 - i][n - 1 - j], // 2 1
						 matrix[n - 1 - j][i]);		   //
			}
		}
	}
	static void printMat(vector<vector<int>> &m)
	{
		for (auto v : m)
		{
			for (auto i : v)
			{
				cout << i << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main() {
	int n;
	vector<vector<int>> m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> v;
		while (1)
		{
			int x;
			cin >> x;
			v.push_back(x);
			if (cin.get() == '\n')
				break;
		}
		m.push_back(v);
	}
	cout << endl;
	Solution::printMat(m);
	Solution s;
	s.rotate(m);
	Solution::printMat(m);
}
