#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited;

void DFS(vector<vector<pair<int,int>>> & g, int id,int p){
	visited[id] = true;
	for(auto & i:g[id]){
		if(p>=i.second&&!visited[i.first]){
			DFS(g, i.first, i.second);
		}
	}
}

int findthebestid(vector<vector<int>>& net, vector<int> & exposed, int n){
	vector<vector<pair<int,int>>> table(n);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i==j) continue;
			pair<int,int> p = {j,net[i][j]};
			table[i].push_back(p);
		}
	}
	int ans = 0;
	int ansid = 0;
	visited.resize(n);
	for(auto & id:exposed){
		DFS(table, id, 10);
		int sum = 0;
		for(auto &i:visited){
			sum+=i;
			i = 0;
		}
		if(ans<=sum){
			ans = sum;
			ansid = id;
		}
	}
	return ansid;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> net(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		int x;
		vector<int> tmp;
		while(cin>>x){
			tmp.push_back(x);
			if(cin.get()=='\n') break;
		}
		net[i] = tmp;
	}
	vector<int> exposed;
	int x;
	while(cin>>x){
		exposed.push_back(x);
		if(cin.get()=='\n') break;
	}
	for(auto& v:net){
		for(auto &i:v){
			cout<<i<<' ';
		}
		cout<<endl;
	}
	for(int & i:exposed){
		cout<<i<<' ';
	}
	cout<<endl;
	cout<<findthebestid(net, exposed, n);
}