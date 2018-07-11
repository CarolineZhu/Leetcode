#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
	
public:
	stack<int> stk;
    stack<int> min;
    
    MinStack() { }
    
    void push(int x) {
        if (min.empty() || min.top() >= x) 
        	min.push(x);
        stk.push(x); 
    }
    
    void pop() {
        if (stk.top() == min.top()) 
        	min.pop();
        stk.pop();
    }
    
    int top() { return stk.top(); }
    
    int getMin() { return min.top(); }
};

int main() {
	MinStack ms;
	ms.push(3);
	cout << ms.getMin();
	ms.push(2);
	cout << ms.getMin();
	ms.pop();
	cout << ms.getMin();
	ms.push(6);
	ms.push(2);
	cout << ms.getMin();
	ms.push(1);
	cout << ms.getMin();

	return 0;
}