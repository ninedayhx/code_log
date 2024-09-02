// tag: 输入输出
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    string name;
    int ans = 0;
    while (ss >> name)
    {
        if (name[0] >= 'A' && name[0] <= 'Z')
        {
            ++ans;
        }
    }
    cout << ans << endl;
}