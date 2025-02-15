// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
// Implement the MinStack class:
//
// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

#include <stack>

using namespace std;

// 2 stacks, one for all elements, one for minimum values
// e.g. 1, 2 -> 1, 1
// time complexity: O(1)
// spac complexity: O(n)
class MinStack
{
private:
	stack<int> st;
	stack<int> minSt;

public:
	MinStack() {}

	void push(int val)
	{
		st.push(val);

		// push onto minSt only if smaller or equal than current minimum element
		if (minSt.empty() || val <= minSt.top())
		{
			minSt.push(val);
		}
		// push current minimum again
		else
		{
			minSt.push(minSt.top());
		}
	}

	void pop()
	{
		st.pop();
		minSt.pop();
	}

	int top() { return st.top(); }

	int getMin() { return minSt.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
