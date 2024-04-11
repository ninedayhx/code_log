#include <iostream>
#include <string>

using namespace std;


// 暴力
int strStr(string haystack, string needle) {
	int m = haystack.size(), n = needle.size(), cnt = 0;
	for (int i = 0; i < m - n + 2; i++) {
		for (int j = 0; j < n; j++){
			if(haystack[i+j]==needle[j]) cnt++;
		}
		if(cnt == n){
			return i;
		}
		cnt = 0;
	}
	return -1;
}

// kmp法进行字符串匹配
int


int main() {
	string str, Str;
	getline(cin, Str);
	getline(cin, str);
	cout << strStr(Str, str);
}
