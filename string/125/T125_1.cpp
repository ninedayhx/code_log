/**
 * leetcode CT150: T125 验证回文串  自己的解法
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
	for (auto i = s.begin(); i != s.end();) {
		if (*i >= 'A' && *i <= 'Z') {
			*i += 32;
		}
		if (!((*i >= 'a' && *i <= 'z')||(*i >= '0' && *i <= '9'))) {
			i = s.erase(i);//删除或者增加元素，原迭代器将失效，
						   //必须获取返回值以更新迭代器
		} else {
			i++;
		}
	}
	cout<<s<<endl;
	int p1 = 0, p2 = s.length() - 1;
	for (int i = 0; i < s.length(); i++) {
		if(s[p1]!=s[p2])
		{
			return false;
		}
		p1++;
		p2--;
	}
	return true;
}


int main() {
	string str = "A man, a plan, a canal: Panama";
	string str1 = "1p";
	cout << isPalindrome(str1);
	return 0;
}