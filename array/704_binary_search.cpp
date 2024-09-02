// tag: binary_search 二分查找
#include <iostream>
#include <vector>

using namespace std;


// 这种方法，没有利用到输入的序列是有序的情况，但是最简单
int regular_search(vector<int> &nums, int target) {
	// auto & 引用，此时不会拷贝，提高效率
	// auto 会发生拷贝，降低效率
	// auto const & 只读
	for (auto &i: nums) {
		if (i == target)
			// nums.data() 获取nums首地址
			return &i - nums.data();
	}
	return -1;
}

// 二分查找，将数据一分为二，比较中间数和目标数的大小，
// target>mid 就进入后半段继续二分
// target<=mid 就进入前半段继续二分
// 循环终止条件不好判断，以及中间的二分流程还得细化
// 所以还需要进一步该改进
int my_binary_search(vector<int> &nums, int target) {
	int n = nums.size();
	if (target > nums[n - 1] || target < nums[0]) return -1;

	int mid, first, last;
	first = 0;
	last = n - 1;
	mid = (first + last) / 2;
	if (nums[first] == target) return first;
	if (nums[mid] == target) return mid;
	if (nums[last] == target) return last;
	while (mid) {
		if (nums[first] == target) return first;
		if (nums[last] == target) return last;
		if (nums[mid] > target) {
			last = mid;
		} else if (nums[mid] < target) {
			first = mid;
		} else if (nums[mid] == target) {
			return mid;
		} else
			return -1;
		mid = (first + last) / 2;
		if (first == mid) {
			return -1;
		}
	}
	return -1;
}

// 采取左闭右闭的方式，进行检索
int binary_search(vector<int> &nums, int target) {
	int left = 0;
	int right = nums.size() - 1;

	// 主要是这里的终止条件需要好好理解，
	// 依据 right = mid - 1;left = mid + 1;的迭代方式
	// 最后 left right mid 三者一定会相等，这时允许其继续循环，
	// 此时将进入离target最近的那个数与其的比较，如果与target相等，return
	// 如果不相等，则要么right-1<left，要么 left+1>right
	// 此时即会退出循环，return -1 ，没有找到目标值
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] > target) {
			// 目标值在左边，因为中间值mid已经在if中比较了，
			// 所以right值可以继续向左移一位
			right = mid - 1;
		} else if (nums[mid] < target) {
			// 同理
			left = mid + 1;
		} else {
			// 找到目标值
			return mid;
		}
	}
	return -1;
}

int main() {
	vector<int> nums;
	int n, tg;
	while (cin >> n) {
		nums.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	cin >> tg;
	cout << regular_search(nums, tg);
	cout << my_binary_search(nums, tg);
	cout << binary_search(nums, tg);

}
