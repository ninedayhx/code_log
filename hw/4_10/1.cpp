#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
	int n;
	cin>>n;
	cin.get();
	for(int i = 0;i<n;i++){
		string in;
		getline(cin,in);
		for(auto &ch:in){
			if(ch==',') ch=' ';
		}
		istringstream ss(in);
		string tmp;
		string time;
		string id;
		string factor;
		ss>>time>>id>>factor>>tmp;
		int timelen = stoi(tmp);
		cout<<time<<' '<<id<<' '<<factor<<' '<<timelen<<endl;
	}
}