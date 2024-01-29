/**
 * leetcode CT150: T125 验证回文串  使用api的解法
 *
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
	string sgood;
	for (char &ch: s) {   // 遍历字符串，依次访问s中的每一个字符,存在ch中，// char &ch: s（直接使用原字符串）快于 char ch: s(需要复制原字符串)
		if (isalnum(ch)) {//cctype 标准库中的函数，判断是否为数字或字母
			sgood += tolower(ch);
		}
	}
	// rbegin() 反向迭代器，通过如下翻转字符串
	string sgood_rev(sgood.rbegin(), sgood.rend());
	cout << sgood << endl
		 << sgood_rev << endl;
	return sgood == sgood_rev;
}


int main() {
	string str = "A man, a plan, a canal: Panama";
	string str1 = "1p";
	cout << isPalindrome(str1);
	return 0;
}