#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 比较函数，用于决定优先队列的排序，在这个函数中，使用pair的第二个元素进行排序，
// 因为是 a.second > b.second 所以将按第二个元素的大小升序排列，队头是最小的元素
static bool cmp(pair<int, int> &a, pair<int, int> &b) {
	return a.second > b.second;
}


vector<int> topKFrequent(vector<int> &nums, int k) {
	unordered_map<int, int> map;
	for (const int &i: nums) {
		map[i]++;
	}
	// 构造一个优先队列 优先队列使用 cmp 函数来比较元素。decltype(&cmp) 会得到 cmp 函数指针的类型。
	// 按元素的出现频率降序排列，是大端堆
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
	// 遍历map
	for (auto &[num, count]: map) {
		// 如果队列中已经有了k个元素，就比较当前数的频率与队头的数的频率
		if (pq.size() == k) {
			// 如果队头频率小于当前值，
			// 则去掉队头，加入当前值
			if (pq.top().second < count) {
				pq.pop();
				pq.emplace(num, count);
			}
		} else {
			pq.emplace(num, count);
		}
	}
	vector<int> res;
	while(!pq.empty()){
		res.emplace_back(pq.top().first);
		pq.pop();
	}
	return res;
}


int main() {
	int n;
	vector<int> nums;
	while (cin >> n) {
		nums.push_back(n);
		if (cin.get() == '\n') break;
	}
	cin >> n;
	vector<int> res = topKFrequent(nums, n);
}
