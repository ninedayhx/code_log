#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isoperator(string s) {
	if (s == "+" || s == "-" || s == "*" || s == "/")
		return true;
	return false;
}

int op_a_b(int a, int b, char ch) {
	switch (ch) {
		case '+' :
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return 0;
	}
}

int evalRPN(vector<string> &tokens) {
	stack<int> st;
	for (const auto &s: tokens) {
		if (!isoperator(s)) {
			st.push(stoi(s));
		}
		if (!st.empty() && isoperator(s)) {
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			st.push(op_a_b(a,b,s[0]));
		}
	}
	return st.top();
}

int main() {
	string str;
	vector<string> tokens;
	while (cin >> str) {
		tokens.push_back(str);
		if (cin.get() == '\n') break;
	}
	for (auto s: tokens) {
		cout << s << ' ';
	}
	cout << endl;
	cout << evalRPN(tokens) << endl;
};