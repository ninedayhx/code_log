// tag: stack
#include <bits/stdc++.h>

using namespace std;

string decodeString(string s)
{
    string ret;
    stack<char> st;
    for (auto &ch : s)
    {
        if (ch == ']')
        {
            string sub = "";
            while (st.top() != '[')
            {
                sub += st.top();
                st.pop();
            }
            reverse(sub.begin(), sub.end());
            st.pop(); // ‘[’
            string num_s = "";
            while (!st.empty() && st.top() >= '0' && st.top() <= '9')
            {
                num_s += st.top();
                st.pop();
            }
            reverse(num_s.begin(), num_s.end());
            int num = stoi(num_s);
            string sub_ext = "";
            for (int i = 0; i < num; ++i)
            {
                sub_ext += sub;
            }
            for (auto &ch : sub_ext)
            {
                st.push(ch);
            }
        }
        else
        {
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        ret += st.top();
        st.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    string s;
    getline(cin, s);
    auto res = decodeString(s);
    cout << res << endl;
}