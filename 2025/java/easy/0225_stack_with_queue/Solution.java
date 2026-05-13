package dev.bakageddy.prepr;

import java.util.LinkedList;
import java.util.Queue;

class MyStack {
	private Queue<Integer> q1;
	private Queue<Integer> q2;

	// True -> q1, False -> q2
	private boolean turn;
    public MyStack() {
		q1 = new LinkedList<>();
		q2 = new LinkedList<>();
		turn = true;
    }
    
    public void push(int x) {
		if (turn) {
			q1.add(x);
		} else {
			q2.add(x);
		}
    }
    
    public int pop() {
		int count = turn ? q1.size() : q2.size();
		if (turn) {
			for (int i = 0; i < count - 1; i++) {
				Integer x = q1.poll();
				q2.add(x);
			}
			return q1.poll();
		} else {
			for (int i = 0; i < count - 1; i++) {
				Integer x = q2.poll();
				q1.add(x);
			}
			return q2.poll();
		}
    }

    public int top() {
		int count = turn ? q1.size() : q2.size();
		if (turn) {
			for (int i = 0; i < count - 1; i++) {
				Integer x = q1.poll();
				q2.add(x);
			}
			turn = !turn;
			int elem = q1.poll();
			q2.add(elem);
			return q1.poll();
		} else {
			for (int i = 0; i < count - 1; i++) {
				Integer x = q2.poll();
				q1.add(x);
			}
			turn = !turn;
			int elem = q2.poll();
			q1.add(elem);
			return elem;
		}
    }
    
    public boolean empty() {
		return turn ? q1.size() == 0 : q2.size() == 0;
    }
}

class MyStackSingle {
	private Queue<Integer> q;

    public MyStack() {
		q = new LinkedList<>();
    }
    
    public void push(int x) {
		q.add(x);
    }
    
    public int pop() {
		int count = q.size();
		for (int i = 0; i < count - 1; i++) {
			q.add(q.poll());
		}
		return q.poll();
    }

    public int top() {
		int count = q.size();
		for (int i = 0; i < count - 1; i++) {
			q.add(q.poll());
		}
		int elem = q.poll();
		q.add(elem);
		return elem;
    }
    
    public boolean empty() {
		return q.size() == 0;
    }
}
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
