/**
 * 经典150题，第28题：找出字符串中第一个匹配项的下标
 */
/**
* leetcode 28 找出字符串中第一个匹配项的下标
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int strStr(string haystack, string needle) {
	int n = haystack.length();
	int m = needle.length();
	for (int i = 0; i < n - m + 1; i++) {
		if (haystack.substr(i, m) == needle) {
			return i;
		}
	}
	return -1;
}


int main() {
	string str1 = "aadbutsad", str2 = "sad";
	cout << strStr(str1, str2);
	return 0;
}