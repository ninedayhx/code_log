#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
	unordered_map<char, int> visit_ran, visit_mage;
	for (const auto &c: magazine){
		visit_mage[c]++;
	}
	for(const auto&c:ransomNote){
		if(visit_mage.find(c)!=visit_mage.end()){
			visit_mage[c]--;
			if(visit_mage[c]<0) return false;
		}else {
			return false;
		}
	}
	return true;
}

int main() {
	char c;
	string ran, mage;
	while (1) {
		getline(cin, ran);
		getline(cin, mage);
		cout << canConstruct(ran, mage)<<endl;
	}
}