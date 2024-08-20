/**
 * @file 155_Min_Stack.cpp
 * @author ninedayhx (1170535490@qq.com)
 * @brief  最小栈的三种实现方法，
 *          1. 使用辅助栈记录每个栈顶元素对应的最小值，即每入栈一个元
 *             素，辅助栈就对应的入一个当前栈的最小值
 *          2. 使用单独一个变量实现1中的辅助栈功能
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/**
 * @brief 使用辅助栈记录每个栈顶元素对应的最小值，即每入栈一个元
 *        素，辅助栈就对应的入一个当前栈的最小值
 *
 */
class MinStack1
{
private:
    stack<int> st, min_st;

public:
    MinStack1()
    {
    }

    void push(int val)
    {
        st.push(val);
        if (min_st.empty())
            min_st.push(val);
        else
            min_st.push(min(val, min_st.top()));
    }

    void pop()
    {
        st.pop();
        min_st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return min_st.top();
    }
};

/**
 * @brief 使用单独一个变量实现1中的辅助栈功能
 *
 */
class MinStack2
{
private:
    stack<int> st;
    int minVal;

public:
    MinStack2(/* args */)
    {
        minVal = -INT_MAX;
    }
    void push(int val)
    {
        if (st.empty())
            minVal = val;
        // 此处需要时等于，因为如果minval==val时，需要压入minval
        // 否则后续pop时，会进行一次没必要的pop
        if (minVal >= val)
        {
            st.push(minVal);
            minVal = val;
        }
        st.push(val);
    }

    void pop()
    {
        if (st.top() == minVal)
        {
            st.pop();
            minVal = st.top();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minVal;
    }
};

int main()
{
}