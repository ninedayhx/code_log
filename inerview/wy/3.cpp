#include <bits/stdc++.h>
using namespace std;

int minOperate(string s){
    
}

int main()
{
    int T;
    cin >> T;
    vector<string> carlist;
    for (int i = 0; i < T; ++i)
    {
        string s;
        cin >> s;
        carlist.emplace_back(s);
    }
    for(auto &s:carlist){
        cout<<minOperate(s)<<endl;
    }
}