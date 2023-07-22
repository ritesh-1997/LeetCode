/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * Implement the MinStack class:
 *
 * MinStack() initializes the stack object.
 *
 * void push(int val) pushes the element val onto the stack.
 *
 * void pop() removes the element on the top of the stack.
 *
 * int top() gets the top element of the stack.
 *
 * int getMin() retrieves the minimum element in the stack.
 *
 * You must implement a solution with O(1) time complexity for each function.
 */
class MinStack
{
public:
    stack<int> st, ss;
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        // checking in min stack if it is empty
        // then push in stack or if top is more
        // than equal to val then push the val
        if (ss.empty() || ss.top() >= val)
        {
            ss.push(val);
        }
    }

    void pop()
    {
        int val = st.top();
        st.pop();
        // checking for min stack
        if (ss.top() == val)
        {
            ss.pop();
        }
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return ss.top();
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