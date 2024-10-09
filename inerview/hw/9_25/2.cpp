// tag:
#include <bits/stdc++.h>

using namespace std;

int numOfSquare(int n, vector<int> vx, vector<int> vy)
{
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (cube[i][j] == 1)
            {
            }
            else
            {
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> sq(n, vector<int>(n, 0));
    vector<int> vx(k), vy(k);
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        sq[x][y] = 1;
        vx[i] = x;
        vy[i] = y;
    }
    cout << numOfSquare(sq) << endl;
}