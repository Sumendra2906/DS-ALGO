#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int idx, int size)
{
    int max_idx = idx;
    int left = 2 * idx;
    int right = left + 1;
    int last = size - 1;
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
        heapify(v, max_idx, size);
    }
}

void buildHeapOptimized(vector<int> &v)
{
    //start from the first non-leaf node
    for (int i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapify(v, i,v.size());
    }
}

void heapsort(vector<int> &v)
{
    buildHeapOptimized(v);
    int n = v.size();

    while (n > 1)
    {
        //swap the first and last
        swap(v[1], v[n - 1]);
        //decrease the size by 1
        n--;
        //call heapify at the root node
        heapify(v, 1, n);
    }
}

int main()
{
    vector<int> v;
    v.push_back(-1);
    int n, no;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        v.push_back(no);
    }
    heapsort(v);
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
