#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int idx)
{
    int max_idx = idx;
    int left = 2 * idx;
    int right = left + 1;
    int last = v.size() - 1;
    if (left <= last and v[left] > v[max_idx])
    {
        max_idx = left;
    }
    if (right <= last and v[right] > v[max_idx])
    {
        max_idx = right;
    }
    if (max_idx != idx)
    {
        swap(v[max_idx], v[idx]);
        heapify(v, max_idx);
    }
}

//O(NlogN)
void buildHeap(vector<int> &v)
{
    for (int i = 2; i < v.size(); i++)
    {
        int idx = i;
        int parent = i / 2;
        //max heap
        while (idx > 1 and v[idx] > v[parent])
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = idx / 2;
        }
    }
}

//O(N)
void buildHeapOptimized(vector<int> &v)
{
    for (int i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapify(v, i);
    }
}

int main()
{
    vector<int> v = {-1, 10, 20, 5, 6, 1, 8, 9, 4};
    buildHeapOptimized(v);
    for (auto it : v)
    {
        cout << it << " ";
    }
}