#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int f, r, cs, ms;

public:
    //constructor
    Queue(int ds = 5)
    {
        arr = new int[ds];
        cs = 0;
        ms = ds;
        f = 0;
        r = ms - 1;
    }
    bool full()
    {
        return ms == cs;
    }
    void push(int data)
    {
        if (!full())
        {
            r = (r + 1) % ms;
            arr[r] = data;
            cs++;
        }
    }
    bool empty()
    {
        return cs == 0;
    }
    void pop()
    {
        if (!empty())
        {
            f = (f + 1) % ms;
            cs--;
        }
    }
    int front()
    {
        return arr[f];
    }
    //destructor
    ~Queue()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main(){
    Queue q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }
    q.pop();
    q.pop();
    q.push(7);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}