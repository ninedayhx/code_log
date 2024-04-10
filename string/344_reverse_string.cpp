#include <iostream>
#include <string>
#include <vector>


using namespace std;

void reverseString(vector<char> &s) {
	int n = s.size();
	for (int i = 0; i < n / 2; i++) {
		swap(s[i], s[n - i - 1]);
	}
}

int main() {
	char ch;
	while (1) {
		vector<char> str;
		while (cin >> ch) {
			str.push_back(ch);
			if (cin.get() == '\n') break;
		}
		for (char c: str) {
			cout << c;
		}
		cout << endl;
		reverseString(str);
		for (char c: str) {
			cout << c;
		}
		cout << endl;
	}
}