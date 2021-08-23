#include <iostream>
#include <queue>
using namespace std;

int join_ropes(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    int cost = 0;
    while (pq.size() > 1)
    {
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();
        int new_rope = A + B;
        cost += A + B;
        pq.push(new_rope);
    }
    return cost;
}

int main()
{
    int n;
    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << join_ropes(arr, n);

    return 0;
}