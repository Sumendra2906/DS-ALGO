#include <iostream>
#include <stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    // we have to move n elements from s1 to s2
    for (int i = 0; i < n; i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}
//O(N2) time and O(N) space.
void reverse(stack<int> &s1)
{
    //take helper stack
    stack<int> s2;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        //take the topmost element
        int x = s1.top();
        s1.pop();
        //move n-i-1 elements to the stack s2
        transfer(s1, s2, n - i - 1);
        //push x to  the original stack
        s1.push(x);
        //move n-i-1 elements back to s1
        transfer(s2, s1, n - i - 1);
    }
}

int main()
{
    stack<int> s1;
    for (int i = 1; i <= 5; i++)
    {
        s1.push(i);
    }
    reverse(s1);
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    return 0;
}