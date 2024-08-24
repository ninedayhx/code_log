// tag:
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> m;
    vector<int> v1 = {1};
    m.push_back(v1);
    for (int i = 1; i < numRows; i++)
    {
        vector<int> vi;
        vi.push_back(1);
        for (int j = 0; j < m[i - 1].size() - 1; j++)
        {
            vi.push_back(m[i - 1][j] + m[i - 1][j + 1]);
        }
        vi.push_back(1);
        m.push_back(vi);
    }
    return m;
}

int main()
{
    int n;
    cin >> n;
    auto mat = generate(n);
    for (auto &v : mat)
    {
        for (auto &i : v)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}