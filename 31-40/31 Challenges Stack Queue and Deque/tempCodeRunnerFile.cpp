#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int data)
    {
        s1.push(data);
    }

    void pop()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int top()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    Queue q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    return 0;
}