#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 直接用栈
string removeDuplicates_stack(string s) {
	stack<char> st;
	for (const char &c: s) {
		if (!st.empty() && st.top() == c) {
			st.pop();
		} else {
			st.push(c);
		}
	}
	int n = st.size();
	string str;
	str.resize(n);
	for (int i = n - 1; i >= 0; i--) {
		str[i] = st.top();
		st.pop();
	}
	return str;
}

// string是可以当栈使用的
string removeDuplicates(string s) {
	string st;
	for (const char &c: s) {
		if (!st.empty() && st.back() == c) {
			st.pop_back();
		} else {
			st.push_back(c);
		}
	}
	return st;
}

int main() {
	string str;
	while (getline(cin, str)) {
		cout << removeDuplicates(str) << endl;
		cout << removeDuplicates_stack(str) << endl;
	}

}
