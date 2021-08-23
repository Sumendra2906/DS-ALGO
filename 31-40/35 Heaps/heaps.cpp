#include <iostream>
#include <vector>
using namespace std;

class Heap
{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b)
    {
        if (minHeap)
        {
            return a < b;
        }
        else
        {
            return a > b;
        }
    }

    void heapify(int idx)
    {
        int min_idx = idx;
        int last = v.size() - 1;
        int left = 2 * idx;
        int right = left + 1;
        if (left <= last and compare(v[left], v[min_idx]))
        {
            min_idx = left;
        }
        if (right <= last and compare(v[right], v[min_idx]))
        {
            min_idx = right;
        }
        if (min_idx != idx)
        {
            swap(v[min_idx], v[idx]);
            heapify(min_idx);
        }
    }

public:
    //constructor
    Heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size);
        //block  the 0th index of the vector
        v.push_back(-1);
        minHeap = type;
    }
    void push(int d)
    {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx / 2;
        //keep checking for the heap property
        while (idx > 1 and compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = idx / 2;
        }
    }

    int top()
    {
        return v[1];
    }

    void pop()
    {
        //swap the first and the last element
        int last = v.size() - 1;
        swap(v[1], v[last]);
        //remove the last element
        v.pop_back();
        //heapify
        heapify(1);
    }
    bool empty(){
        return (v.size() == 1);
    }
};

int main()
{
    Heap h(10,false);
    int n,no;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> no;
        h.push(no);
    }
    while(!h.empty()){
        cout << h.top()<<" ";
        h.pop();
    }
    return 0;
}