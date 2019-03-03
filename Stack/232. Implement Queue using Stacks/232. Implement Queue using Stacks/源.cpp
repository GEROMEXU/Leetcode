#include <iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
class MyQueue1 {
	stack<int> input, output;
public:
	/** Initialize your data structure here. */
	MyQueue1() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		input.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int num = peek();
		output.pop();
		return num;
	}

	/** Get the front element. */
	int peek() {
		if (output.empty())
			while (input.size())
				output.push(input.top()), input.pop();
		return output.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return input.empty() && output.empty();
	}
};

class MyQueue2 {
private:
	stack<int> st;
public:
	/** Initialize your data structure here. */
	MyQueue2() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stack<int> tmp;
		while (!st.empty())
		{
			tmp.push(st.top());
			st.pop();
		}
		st.push(x);
		while (!tmp.empty())
		{
			st.push(tmp.top());
			tmp.pop();
		}

	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int value;
		value = st.top();
		st.pop();
		return value;
	}

	/** Get the front element. */
	int peek() {
		return st.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return st.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
