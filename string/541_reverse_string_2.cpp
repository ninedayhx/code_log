#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 第一版本，写的比较乱
string myreverseStr(string s, int k) {
	int p = 0, n = s.size();
	while (p <= n) {
		if ((n - p) < k) {
			for (int j = 0; j < (n - p) / 2; j++) {
				swap(s[p + j], s[p + (n - p) - 1 - j]);
			}
			break;
		} else if ((n - p) >= k && (n - p) < 2 * k) {
			for (int j = 0; j < k / 2; j++) {
				swap(s[p + j], s[p + k - 1 - j]);
			}
			break;
		}
		for (int i = 0; i < k / 2; i++) {
			swap(s[p + i], s[p + k - 1 - i]);
		}
		p += 2 * k;
	}
	return s;
}

void reverse_str(string &s, int start, int end) {
	for (int i = 0; i < (start - end + 1) / 2; i++) {
		swap(s[start+i], s[end -i]);
	}
}

string reverseStr(string s, int k) {
	int p = 0, n = s.size();
	while (p <= n) {
		if ((n - p) < k) {
			for (int j = 0; j < (n - p) / 2; j++) {
				swap(s[p + j], s[p + (n - p) - 1 - j]);
			}
			break;
		}
		for (int i = 0; i < k / 2; i++) {
			swap(s[p + i], s[p + k - 1 - i]);
		}
		p += 2 * k;
	}
	return s;
}

int main() {
	char ch;
	while (1) {
		string str;
		getline(cin, str);
		cout << str << endl;
		int k;
		cin >> k;
		string ans = reverseStr(str, k);
		cout << ans << endl;
	}
}
