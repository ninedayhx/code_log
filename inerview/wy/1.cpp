#include <bits/stdc++.h>
using namespace std;

double crowd(vector<vector<int>> &g, vector<int> box)
{
    int xl = box[0]-1, xr = box[1]-1, yl = box[2]-1, yr = box[3]-1;
    int size = (xr-xl+1)*(yr-yl+1);
    int num1 = 0;
    for(int i = xl;i<=xr;++i){
        for(int j = yl;j<=yr;++j){
            if(g[i][j]==1)
                num1++;
        }
    }
    return (double)num1/(double)size;
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g;
    cin.get();
    for (int i = 0; i <n; ++i)
    {
        string s;
        getline(cin, s);
        vector<int> line;
        for (auto &ch : s)
        {
            line.push_back(ch - '0');
        }
        g.push_back(line);
    }
    // for(auto &v:g){
    //     for(auto &i:v){
    //         cout<<i<<' ';
    //     }
    //     cout<<endl;
    // }
    vector<vector<int>> boxs(q, vector<int>(4));
    for (int i = 0; i < q; ++i)
    {
        cin >> boxs[i][0] >> boxs[i][1] >> boxs[i][2] >> boxs[i][3];
    }
    // for (auto &v : boxs)
    // {
    //     for (auto &i : v)
    //     {
    //         cout << i << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < q; ++i)
    {
        cout << fixed << setprecision(8) << crowd(g, boxs[i]) << endl;
    }
}