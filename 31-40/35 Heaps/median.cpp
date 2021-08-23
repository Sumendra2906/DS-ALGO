#include <iostream>
#include <queue>
using namespace std;

//median in a running stream of integers
void median()
{
    //max heap
    priority_queue<int> left_heap;
    //min heap
    priority_queue<int, vector<int>, greater<int>> right_heap;
    int d;
    cin >> d;
    left_heap.push(d);
    float md = d;
    cout << "Median is " << md << endl;
    cin >> d;
    while (d != -1)
    {
        if (left_heap.size() > right_heap.size())
        {
            if (d < md)
            {
                //push the topmost element to the right
                right_heap.push(left_heap.top());
                left_heap.pop();
                left_heap.push(d);
            }
            else
            {
                right_heap.push(d);
            }
            md = (left_heap.top() + right_heap.top()) / 2.0;
        }
        else if (left_heap.size() == right_heap.size())
        {
            if (d < md)
            {
                left_heap.push(d);
                md = left_heap.top();
            }
            else
            {
                right_heap.push(d);
                md = right_heap.top();
            }
        }
        else
        {
            //right heap is larger
            if (d > md)
            {
                left_heap.push(right_heap.top());
                right_heap.pop();
                right_heap.push(d);
            }
            else
            {
                left_heap.push(d);
            }
            md = (left_heap.top() + right_heap.top()) / 2.0;
        }

        cout << "Median is " << md << endl;
        cin >> d;
    }
}

int main()
{
    median();
    return 0;
}