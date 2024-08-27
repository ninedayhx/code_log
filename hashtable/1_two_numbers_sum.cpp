// tag array hashtable
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
	int len = nums.size();
	int next = 0;
	vector<int> res;
	for (int i = 0; i < len; i++) {
		next = target - nums[i];
		for (int j = i + 1; j < len; j++) {
			if (next == nums[j]) {
				res.push_back(i);
				res.push_back(j);
				return res;
			}
		}
	}
	return res;
}

vector<int> twoSum_hash(vector<int> &nums, int target) {
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (map.find(target - nums[i]) != map.end())
		{
			return {map[target - nums[i]], i};
		}
		map[nums[i]] = i;
	}
}

int main() {
	int n, tag;
	vector<int> nums, res;
	while (1) {
		while (cin >> n) {
			nums.push_back(n);
			if (cin.get() == '\n') break;
		}
		cin >> tag;
		res = twoSum(nums, tag);
		for (const auto &i: res) {
			cout << i << ' ';
		}
		cout << endl;
	}
}