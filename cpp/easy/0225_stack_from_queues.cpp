#include <queue>

class MyStack {
	std::queue<int> q1;
public:
    MyStack() {
		q1 = {};
    }
    
    void push(int x) {
		q1.push(x);
    }
    
    int pop() {
		int temp = {};
		for (int i = 0; i < q1.size() - 1; i++) {
			temp = q1.front();
			q1.pop();
			q1.push(temp);
		}
		temp = q1.front();
		q1.pop();
		return temp;
    }
    
    int top() {
		int temp = {};
		for (int i = 0; i < q1.size() - 1; i++) {
			temp = q1.front();
			q1.pop();
			q1.push(temp);
		}
		temp = q1.front();
		q1.pop();
		q1.push(temp);
		return temp;
    }
    
    bool empty() {
		return q1.empty();
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
