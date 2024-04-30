#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

vector<string> test(vector<string> vs){
	stack<string> st;
	for(auto & s:vs){
		if(st.empty()) st.push(s);
		else if (s==st.top()){
			string tmp = st.top();
			st.pop();
			if(!st.empty()&&s==st.top()) {
				st.pop();
			}else {
				st.push(tmp);
				st.push(s);
			}
		}else {
			st.push(s);
		}

	}
	vector<string> res;
	while(!st.empty()){
		res.push_back(st.top());
		st.pop();
	}
	reverse(res.begin(), res.end());
	if(res.empty()) res.push_back("0");
	return res;
}

int main(){
	int n;
	string s;
	vector<string> res;
	vector<string> vstr;
	cin>>n;
	while(cin>>s){
		vstr.push_back(s);
		if(cin.get()=='\n') break;
	}
	res = test(vstr);
	for(auto & s:res){
		cout<< s<<' ';
	}
	cout<<endl;
}