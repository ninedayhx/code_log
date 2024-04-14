#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
	queue<int> tmp;
public:
	MyStack() {

	}

	void push(int x) {
		tmp.push(x);
	}

	int pop() {
		int n = tmp.size();
		int res = tmp.back();
		for(int i=0;i<n-1;i++){
			tmp.push(tmp.front());
			tmp.pop();
		}
		tmp.pop();
		return res;
	}

	int top() {
		return  tmp.back();
	}

	bool empty() {
		return tmp.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){
	MyStack * obj = new MyStack();
	for(int i =0;i<4;i++){
		obj->push(i+1);
	}
	cout<<obj->top();
	for(int i = 0;i<4;i++){
		cout<<obj->pop()<<' ';
	}
	cout<<endl;
}