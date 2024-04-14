#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;


// 暴力解法会超时
vector<int> maxSlidingWindow_brute_force(vector<int> &nums, int k) {
	vector<int> res;
	auto it = nums.begin();
	for (int i = 0; i < nums.size() - k + 1; i++) {
		res.push_back(*max_element(it + i, it + i + k));
	}
	return res;
}

// 使用优先队列来做
// 优先队列，就是有序的队列，可以定义为从大端和小段两种模式，默认为大端
// 滑动窗口每移动一次，就把新元素入队，然后取优先队列的队首。
// 但是如果队首的index不在滑动窗口的范围内，就把队首给去除，保证优先队列中的最大元素始终在滑动窗口的范围内
// 所以队列不仅仅需要记录数组值还需要记录index,所以需要使用pair
vector<int> maxSlidingWindow_priorityqueue(vector<int> &nums, int k) {
	int n = nums.size();
	vector<int> res;
	// 对于pair的比较为，先比较第一个，相等再比较第二个
	priority_queue<pair<int, int>> pq;
	// priority_queue<int> a; 大端队列，从首到尾是从大到小
	// 等同于 priority_queue<int, vector<int>, less<int> > a;
	// 小端队列，升序排列
	// priority_queue<int, vector<int>, greater<int> > a

	// 初始化窗口
	for (int i = 0; i < k; i++) {
		pq.emplace(nums[i], i);
	}
	res.push_back(pq.top().first);

	// 之后只要每次放一个元素进去，然后比较top的index是否合法，
	// 循环中窗口的范围为[i-k+1,i],所以top的index要小于i-k+1
	for (int i = k; i < n; i++) {
		pq.emplace(nums[i], i);
		// 此时不能用if,而是while
//		if (pq.top().second < i - k + 1) {
//			pq.pop();
//		}

		// 循环检查队列中的top是否合法，全部合法以后，再取top()
		while (pq.top().second < i - k + 1) {
			pq.pop();
		}
		res.push_back(pq.top().first);
	}
	return res;
}

// 单调队列
// 如果一个队列是单调队列，那个这个队列的队首一定是最大值，
// 那么如何维护这个单调队列呢，假设在滑动窗口的过程中，我们有这样一个队列dq，现在窗口向右移动一位，
// 则需要新加入一个元素，队尾的元素在数组中的index一定小于要加入的元素的index,如果队尾元素小于新加入元素
// 那么队尾元素一定不是当前窗口最大值，那么就把它移除，循环这个操作，直到新加入元素小于队尾元素，这样就使得队列是一个单调队列。
// 队列的最大值就是top处的值，但是top处值的index不一定在窗口内，所以需要判断其在不在窗口内，不在窗口内，就需要将其去除，
// 由于既需要去除队尾，又需要去除队首元素，所以使用双端队列。
// 可以看出，我们只需要知道index就行，具体值只需要通过index访问原数组就行，所以队列存的元素就是index
vector<int> maxSlidingWindow_monotonicqueue(vector<int> &nums, int k) {
	int n = nums.size();
	vector<int> res;
	// 因为需要弹出队首和队尾的元素，所以使用双端队列
	deque<int> dq;
	// 初始化窗口
	for(int i =0;i<k;i++){
		// 循环比较队尾元素与新加入元素，维护队列的单调性
		while(!dq.empty()&&nums[i]>=nums[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	// 将窗口最大值存入结果
	res.push_back(nums[dq.front()]);
	// 开始滑动窗口
	for(int i =k;i<n;i++){
		// 循环比较队尾元素与新加入元素，维护队列的单调性
		while(!dq.empty()&&nums[i]>=nums[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
		// 检查队首元素是否在窗口内
		while(dq.front()<i-k+1){
			dq.pop_front();
		}
		res.push_back(nums[dq.front()]);
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
	vector<int> res = maxSlidingWindow_brute_force(nums, n);
	for (auto i: res) {
		cout << i << ' ';
	}
	cout << endl;

	res = maxSlidingWindow_priorityqueue(nums, n);
	for (auto i: res) {
		cout << i << ' ';
	}
	cout << endl;


	res = maxSlidingWindow_monotonicqueue(nums, n);
	for (auto i: res) {
		cout << i << ' ';
	}
	cout << endl;
}