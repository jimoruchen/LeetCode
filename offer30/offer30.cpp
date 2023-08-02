#include<iostream>
#include<stack>
using namespace std;

class MinStack {
private:
    stack<int> stk1,stk2;
public:
    /** initialize your data structure here. */
    
    MinStack() {}
    
    void push(int x) {
        stk1.push(x);
        if(stk2.empty())
            stk2.push(x);
        else if(stk2.top() >= x)
            stk2.push(x);
    }
    
    void pop() {
        if(stk1.top() == stk2.top())
            stk2.pop();
        stk1.pop();
    }

    int top(){
        return stk1.top();
    }
    
    int min(){ 
        return stk2.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.min() << endl;   
    minStack.pop();
    cout << minStack.top() << endl;      
    cout << minStack.min() << endl;
    system("pause");
    return 0;
}