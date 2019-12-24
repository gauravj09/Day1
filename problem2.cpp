#include <iostream>
#include<stdlib.h>
#include <stack>

using namespace std;

/*
Two Stack Solution

Approach: Maintain a minStack which keeps track of minimum value for each push operation. 
Run-time Complexity: O(1)

*/

class specialStack
{
    public:
        int minimumElement;
        stack<int> myStack;
        stack<int> minStack;

        void push(int element)
        {
            myStack.push(element);

            if(minStack.empty()) 
                minStack.push(element);

            else
                minStack.top() > myStack.top() ? minStack.push(element) : minStack.push(minStack.top());
        
            return;
        }

        int pop()
        {
            int top = myStack.top();
            minStack.pop();
            myStack.pop();

            return top;
        }
        
        bool isEmpty()
        {
            return myStack.empty();
        }

        int getMin()
        {
            return minStack.top();
        }

};

/* Driver program to test SpecialStack methods */
int main() 
{ 
    specialStack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout<<s.getMin()<<endl; 
    s.push(5); 
    cout<<s.getMin()<<endl; 
    return 0; 
}
