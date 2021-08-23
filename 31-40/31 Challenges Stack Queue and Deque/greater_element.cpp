#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<int> s;
    //maintain an array to preserve the order and the output it
    unordered_map<int, int> ans;
    s.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() and arr[i] > s.top())
        {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(arr[i]);
    }
    while (!s.empty())
    {
        ans[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[arr[i]] << " ";
    }

    delete[] arr;
    return 0;
}