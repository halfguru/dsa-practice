// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the
// functions of a normal queue (push, peek, pop, and empty).
//
// Implement the MyQueue class:
//
// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes:
//
// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty
// operations are valid. Depending on your language, the stack may not be supported natively. You may simulate a stack
// using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
#include <stack>

using namespace std;

// queue is FIFO, first in first out
// 2 stacks, 1 for enqueue, 1 for dequeue
// time complexity: O(1) for push, pop
// space complexity: O(n)
class MyQueue
{
private:
	stack<int> s1;
	stack<int> s2;

public:
	MyQueue() {}

	void push(int x) { s1.push(x); }

	int pop()
	{
		if (s2.empty())
		{
			// transfer elements from s1 to s2
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		const int topVal = s2.top();
		s2.pop();
		return topVal;
	}

	int peek()
	{
		if (s2.empty())
		{
			// transfer elements from s1 to s2
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}

	bool empty() { return s1.empty() && s2.empty(); }
};
