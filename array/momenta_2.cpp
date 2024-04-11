#include <iostream>
#include <vector>

using namespace std;

//input1 rank = { 100, 90 ,90, 80};
//input2 score = {60, 90, 110};
//out    getrank = {4, 2, 1 };

vector<int> getrank(vector<int> rank, vector<int> s) {
	vector<int> v;
	for (auto i: s) {
		for (int j = 0; j < rank.size(); j++) {
			if (i >= rank[j]){
				v.push_back(j + 1);
				break;
			}
			if(j == (rank.size()-1)&&i < rank[j]){
				v.push_back(j+1);
			}
		}
	}
	return v;
}

int main() {
	int n;
	vector<int> r, s, res;
	while (cin >> n) {
		r.push_back(n);
		if (cin.get() == '\n') break;
	}
	while (cin >> n) {
		s.push_back(n);
		if (cin.get() == '\n') break;
	}
	res = getrank(r, s);
	for (auto i: res) {
		cout << i << ' ';
	}
	cout << endl;
}
