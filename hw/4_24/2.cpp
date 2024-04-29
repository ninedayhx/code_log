/**
 * hw 0424 题二 足球队员射门能力排序
 * n个队员参与m次射门训练，每次射入球用1表示，没射入用0表示，
 * 依据如下规则对各个队员能力进行排序
 * 1. 进球总数更多的球员能力强
 * 2. 若进球数量一致，则最多一次连续进球次数的球员能力强
 * 3. 若最多一次连续进球数量一致，则比较第一次射失的前后顺序，后丢球的队员能力更强
 * 4. 若前三个规则能力全一致，则队员编号小的能力强
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

struct teamer{
	int sum,cont,id;
	string shout;
};

// 为结构体构建比较函数，作为sort的排序比较函数
bool cmp(teamer a, teamer b){
	if(a.sum != b.sum) return a.sum > b.sum;
	if(a.cont != b.cont) return a.cont > b.cont;
	// 可以使用字典顺序进行直接排序
	if(a.shout != b.shout) return a.shout > b.shout;
	return a.id < b.id;
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<teamer> team(n);
	for(int i = 0; i<n; i++){
		team[i].id = i+1;
		// 统计射门次数
		cin>>team[i].shout;
		int tmp = 0;
		// 统计射门连续中球最大次数
		for(auto &ch:team[i].shout){
			if(ch=='1'){
				team[i].sum++;
				tmp++;
			}else if(ch=='0'){
				team[i].cont = max(tmp, team[i].cont);
				tmp = 0;
			}
		}
		// 统计射门进球次数
		team[i].cont = max(tmp, team[i].cont);
	}
	// 使用api进行比较
	sort(team.begin(), team.end(),cmp);
	for(int i = 0;i<team.size()-1;i++){
		cout<<team[i].id<<' ';
	}
	cout<<team[team.size()-1].id;
}