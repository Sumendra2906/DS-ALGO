#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n, k, i;
    int arr[1001];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    //we have to process first k element sepertely
    deque<int> Q(k);

    for (i = 0; i < k; i++)
    {
        while (!Q.empty() and (arr[i] > arr[Q.back()]))
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    //after this element we will have the index of the largest  element from the first k elements

    //process the remaining elements
    for (; i < n; i++)
    {
        cout << arr[Q.front()] << " ";
        //Remove the elements that are not in the window
        while (!Q.empty() and Q.front() <= i - k)
        {
            Q.pop_front();
        }
        //Remove the  elements that are not useful but are in the window
        while (!Q.empty() and (arr[i] > arr[Q.back()]))
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    cout << arr[Q.front()];

    return 0;
}