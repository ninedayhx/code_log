// tag: stl
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        long long d1, d2, v1, v2;
        cin >> d1 >> d2 >> v1 >> v2;
        double t = ((double)d1 - (double)d2) / ((double)v2 - (double)v1);
        cout << fixed << setprecision(6) << t << endl;
    }
}