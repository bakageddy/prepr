#include <stack>
class MyQueue {
	std::stack<int> one;
	std::stack<int> two;

	void transferStacks(void) {
		if (two.empty()) {
			while (!one.empty()) {
				two.push(one.top());
				one.pop();
			}
		} else {
			while (!two.empty()) {
				one.push(two.top());
				two.pop();
			}
		}
	}
public:
    MyQueue() {
		one = {};
		two = {};
    }
    
    void push(int x) {
		one.push(x);
    }
    
    int pop() {
		transferStacks();
		int temp = two.top();
		two.pop();
		transferStacks();
		return temp;
    }
    
    int peek() {
		transferStacks();
		int temp = two.top();
		transferStacks();
		return temp;
    }
    
    bool empty() {
		return one.empty();
    }
};
