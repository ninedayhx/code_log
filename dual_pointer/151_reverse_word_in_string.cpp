#include <iostream>
#include <string>

using namespace std;

//input = "    hello    world "
//output = "world hello"
// 所以需要通过如下步骤，
// 1.去除多余的空格  变为"hello world"
// 2.翻转整个字符串  变为"dlrow olloh"
// 3.翻转单独的单词  变为"world hello"

class Solution {
public:
	// 双指针法移除多余空格
	void removeblank(string &s) {
		int slow = 0, fast = 0;
		while(fast<s.size()){
			if(s[fast]!=' '){
				if(slow!=0) s[slow++] = ' ';
				while(fast<s.size()&&s[fast]!=' '){
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

