#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	// 双指针法移除多余空格
	void removeblank(string &s) {
		int slow = 0, fast = 0;
		while (fast < s.size()) { // 快指针用来找到需要换的地方
			if (s[fast] != ' ') { // 如果不是空格，则说明需要换到慢指针的数据
				if (slow != 0) s[slow++] = ' '; // 这里是主动增加空格，用来分割每一个word
				while (fast < s.size() && s[fast] != ' ') { // 这里等于把一整个word往前移动
					s[slow++] = s[fast++];
				}
			}
			fast++;
		}
		s.resize(slow);
	}

	// 将整个字符串翻转
	void reversestring(string &s) {
		int n = s.size();
		for (int i = 0; i < n / 2; i++) {
			swap(s[i], s[n - 1 - i]);
		}
	}

	void reverse(string &s, int start, int end) {
		for (int i = start, j = end; i < j; i++, j--) {
			swap(s[i], s[j]);
		}

	}

	string reverseWords(string s) {
		removeblank(s);
		cout << s << endl;
		reversestring(s);
		cout << s << endl;
		int start = 0;
		for (int i = 0; i <= s.size(); ++i) {
			if (i == s.size() || s[i] == ' ') {
				reverse(s, start, i - 1);
				start = i + 1;
			}
		}
		return s;
	}
};

int main() {
	while (1) {
		string str, res;
		getline(cin, str);
		cout << str << endl;
		Solution solver;
		res = solver.reverseWords(str);
		cout << res << endl;
	}
}

