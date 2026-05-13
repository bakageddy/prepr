package dev.bakageddy.prepr;

import java.util.Stack;

public class MyQueue {
	private Stack<Integer> stk1;
	private Stack<Integer> stk2;
	private boolean turn;

    public MyQueue() {
		stk1 = new Stack<>();
		stk2 = new Stack<>();
		turn = true;
    }
    
    public void push(int x) {
		if (turn)
			stk1.push(x);
		else
			stk2.push(x);
    }
    
    public int pop() {
		if (turn) {
			for (int i = 0; i < stk1.size() - 1; i++) {
				stk2.push(stk1.pop());
			}
			return stk1.pop();
		} else {
			for (int i = 0; i < stk2.size() - 1; i++) {
				stk1.push(stk2.pop());
			}
			return stk2.pop();
		}
    }
    
    public int peek() {
		if (turn) {
			for (int i = 0; i < stk1.size() - 1; i++) {
				stk2.push(stk1.pop());
			}
			int elem = stk1.pop();
			stk2.push(elem);
			return elem;
		} else {
			for (int i = 0; i < stk2.size() - 1; i++) {
				stk1.push(stk2.pop());
			}
			int elem = stk2.pop();
			stk1.push(elem);
			return elem;
		}
    }
    
    public boolean empty() {
		return (turn ? stk1.size() : stk2.size()) == 0;
    }
}
