#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue {
public:
	stack<int> stkA;
	stack<int> stkB;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
    	stkA.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!stkA.empty()) {
        	stkB.push(stkA.top());
        	stkA.pop();
        }
        int ret = stkB.top();
        stkB.pop();
        while(!stkB.empty()) {
        	stkA.push(stkB.top());
        	stkB.pop();
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        while(!stkA.empty()) {
        	stkB.push(stkA.top());
        	stkA.pop();
        }
        int ret = stkB.top();
        while(!stkB.empty()) {
        	stkA.push(stkB.top());
        	stkB.pop();
        }
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stkA.empty();
    }
};

int main() {
	MyQueue queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);  
	cout << queue.peek();  // returns 1
	cout << queue.pop();   // returns 1
	queue.push(4);
	cout << queue.pop();
	cout << queue.empty();
	return 0;
}