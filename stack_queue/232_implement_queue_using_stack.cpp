#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
private:
	stack<int> in;
	stack<int> out;
public:
	// 因为stack是先进后出，而queue是先进先出，
	// 所以如果使用两个栈，就可以把顺序调换为queue的顺序
	// 一个作为输入栈，一个作为输出栈

	MyQueue() {

	}

	// 入队操作
	void push(int x) {
		in.push(x); // 数据进输入栈
	}

	// 出队操作
	int pop() {
		// 如果输出栈中没有元素了，就把所有的输入栈中的元素
		// 全部放到输出栈中，如果没有放入全部元素，就会出现顺序混乱
		if(out.empty()){
			while(!in.empty()){
				// top获取栈顶的元素
				out.push(in.top());
				// 然后出栈
				in.pop();
			}
		}
		int res = out.top();
		out.pop();
		return res;
	}

	// 返回队列首部的元素
	int peek() {
		// 要保证输出栈非空
		if(out.empty()){
			while(!in.empty()){
				// top获取栈顶的元素
				out.push(in.top());
				// 然后出栈
				in.pop();
			}
		}
		return out.top();
	}

	// 查询队列是否为空
	bool empty() {
		return in.empty()&&out.empty();
	}
};


int main(){
	MyQueue* obj = new MyQueue();
	int x;
	cin>>x;
	obj->push(x);
	int param_2 = obj->pop();
	int param_3 = obj->peek();
	bool param_4 = obj->empty();

}