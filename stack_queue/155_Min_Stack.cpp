#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> st, min_st;
    int minVal = -INT32_MIN;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        minVal = min(minVal, val);
        st.push(val);
        if (min_st.empty())
        {
            min_st.push()
        }
    }

    void pop()
    {
        if (st.top())
            st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
}