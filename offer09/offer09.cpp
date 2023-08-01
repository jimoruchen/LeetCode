#include<iostream>
#include<stack>
using namespace std;

class CQueue {
public:
    stack<int> stk1;
    stack<int> stk2;

    CQueue() {}
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        int ans = -1;
        while(!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        if(!stk2.empty())
        {
            ans = stk2.top();
            stk2.pop();
        }
        while(!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ans;
    }
};

int main()
{
    CQueue queue;
    queue.appendTail(1);
    queue.appendTail(2); 
    queue.appendTail(3);
    cout << queue.deleteHead() << endl;
    cout << queue.deleteHead() << endl; 
    cout << queue.deleteHead() << endl;  
    system("pause");
    return 0;   
}