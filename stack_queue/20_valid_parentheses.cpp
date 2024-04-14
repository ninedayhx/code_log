#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
	stack<char> st;
	int n = s.size();
	if (n % 2 != 0) return false;
	for (const char &c: s) {
		if (!st.empty()) {
			if (st.top() == '{' && c == '}') {
				st.pop();
				continue;
			}
			if (st.top() == '[' && c == ']') {
				st.pop();
				continue;
			}
			if (st.top() == '(' && c == ')') {
				st.pop();
				continue;
			}
			st.push(c);
		} else {
			st.push(c);
		}
	}
	if (!st.empty()) return false;
	else return true;
}

int main() {
	string str;
	while (getline(cin, str)) {
		cout << isValid(str) << endl;
	}

}

