#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
	if (s.length() != t.length()) {
		return false;
	}
	// 使用数组作为哈希表
	vector<int> table(26, 0);
	for (auto& ch: s) {
		table[ch - 'a']++;
	}
	for (auto& ch: t) {
		table[ch - 'a']--;
		if (table[ch - 'a'] < 0) {
			return false;
		}
	}
	return true;
}


int main() {
	string a, b;
	while (cin >> a >> b) { // 注意 while 处理多个 case
		cout << "a:" << a << endl;
		cout << "b:" << b << endl;
		cout << isAnagram(a, b) << endl;
	}
}