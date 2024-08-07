/**
 * 编写一个程序为某云服务计算客户话单，输入为某云服务的计费日志和各种计费因子
 * 的计费单价的列表，计费日志内容包含时间戳、客户标识、计费因子、计费时长4个字
 * 段。日志中如果同一客户同一计费因子在相同时间戳上报多次话单只能计费一次，选先
 * 上报的日志计费。计算每个客户的话单总费用。
 * 解答要求
 * 时间限制: C/C++ 1000ms,其他语言: 2000ms内存限制: C/C++ 256MB,其他语言: 512MB
 *
 * 输入
 * 第1行表示计费日志的条数n，是一个正整数，范围是1<=n<=1000
 * 第2到n+1行表示云服务的计费日志，共4列，
 * 		第1列表示时间戳(是一个数字字符串，长度为10)
 * 		第2列表示客户标识(是一个字符串，长度为1-16)
 * 		第3列表示计费因子 (是一个字符串，长度为1-16，计费因子查不到时认为计费因子单价是0）
 * 		第4列表示计费时长时长（范围为0-100，当计费时长不在范围内要认为是计费日志有问题，当成计费为0处理)，
 * 这4个字段使用逗号分隔。
 * 第n+2行表示计费因子的数量m，m是一个正整数，范围是1<=m<=100
 * 第n+3到n+3+m行表示各种计费因子的计费单价的列表，该表有2列,
 * 		第1列表示计费因子(是一个字符串，长度为1-16)
 * 		第2列表示单价(是一个正整数，范围为1~100)，这2个字段使用逗号分
 *
 * 输出
 * 每个客户的话单总费用,共2列，
 * 		第1列表示客户名，
 * 		第2列表示话单费用
 * 2列用逗号分割，输出按客户标识字典序升序排序
 * eg1
 * input:
	5
	1627845600,client1,factorA,10
	1627845605,client2,factorB,15
	1627845610,client1,factorA,5
	1627845610,client1,factorB,8
	1627845620,client2,factorB,20
	2
	factorA,5
	factorB,7
 * output:
	client1,131
	client2,245
 解释 client1 5*10+5*5+7*8=131
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct factor_t {
	unordered_set<string> timestamp;
	int timelen;
};

int main() {
	unordered_map<string, int> factormap;
	// 使用map作为容器，则存储时自然按字典顺序排列
	map<string, unordered_map<string, factor_t>> client;
	int n;
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++) {
		string in;
		getline(cin, in);
		for (auto &ch: in) {
			if (ch == ',') ch = ' ';
		}
		istringstream ss(in);
		string timestamp, id, factor, timelen;
		ss >> timestamp >> id >> factor >> timelen;
		// 如果之前没有输入过这个id或者这个id对应的因子
		if (!client.count(id) || !client[id].count(factor)) {
			factor_t tmp;
			tmp.timestamp.insert(timestamp);
			tmp.timelen = stoi(timelen);
			client[id][factor] = tmp;
		} else { // 输入过这个id以及对应的因子
			// 如果有相同的时间戳
			if (client[id][factor].timestamp.count(timestamp)) {
				continue;
			} else {
				client[id][factor].timestamp.insert(timestamp);
				client[id][factor].timelen += stoi(timelen);
			}
		}
	}
	int factor_num;
	cin >> factor_num;
	cin.get();
	for (int i = 0; i < factor_num; i++) {
		string in;
		getline(cin, in);
		for (auto &ch: in) {
			if (ch == ',') ch = ' ';
		}
		istringstream ss(in);
		string factor;
		int pay;
		ss >> factor >> pay;
		factormap[factor] = pay;
	}
	for (auto &i: client) {
		int cost = 0;
		for (auto &j: i.second) {
			cost += factormap[j.first] * j.second.timelen;
		}
		cout << i.first << ',' << cost << endl;
	}
}