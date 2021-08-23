#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stack
{
    queue<T> q1, q2;
    //we wil keep the q2 queue as empty

public:
    void push(T x)
    {
        q1.push(x);
    }
    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        while (q1.size() > 1)
        {
            T temp = q1.front();
            q2.push(temp);
            q1.pop();
        }
        q1.pop();
        //swap the names
        swap(q1, q2);
    }
    T top()
    {
        while (q1.size() > 1)
        {
            T temp = q1.front();
            q2.push(temp);
            q1.pop();
        }
        T element = q1.front();
        q1.pop();
        q2.push(element);
        //swap the names
        swap(q1, q2);
        return element;
    }
    int size()
    {
        return q1.size() + q2.size();
    }
    bool empty()
    {
        return size() == 0;
    }
};

int main()
{
    Stack<int> s;
    for(int i=1;i<=10;i++){
        s.push(i);
    }
    s.pop();
    s.pop();
    s.pop();
    while(!s.empty()){
        cout<<s.top()<< " ";
        s.pop();
    }
    return 0;
}