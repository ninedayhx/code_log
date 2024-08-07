/**
 * 扑克牌消除
 *
 * 从一副扑克牌中随机抽取n张牌组成一个序列，规定连续3张相同牌号的卡牌可以消除，
 * 剩余卡牌按照当前顺序重新合并成新的序列后继续消除，重复以上步骤直到无法消除，
 * 最后请输出结束后剩余的卡牌序列。注:存在连续4张相同牌号的情况，消除后剩余一张。
 *
 * 解答要求：时间限制:C/C++1000ms, 其他语言:2000ms内存限制: C/C++256MB,其他语言:512MB
 *
 * 输入
 * 第一行一个正整数n(1 <n< 52)，表示卡牌的数量。
 * 第二行一个字符串，以空格分隔代表卡牌号序列，卡牌号仅包含2-10,A,J,Q,K.
 *
 * 输出
 * 1个字符串，打印最终结束后的卡牌号序列，卡牌号以空格分隔，如果最终没有卡牌剩余输出0。
 *
 * eg
 * input:	10
 * 			3 A 2 2 2 A A 7 7 7
 * output:  3
 */

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