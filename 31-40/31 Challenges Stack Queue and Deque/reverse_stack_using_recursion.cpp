#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x)
{
    //base case
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
}

void reverse(stack<int> &s)
{
    //base case
    if (s.empty())
    {
        return;
    }
    //recursive case
    //take the topmost element and push it to the bottom of the smaller reversed stack
    int x = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, x);
}

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        s.push(data);
    }
    reverse(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}