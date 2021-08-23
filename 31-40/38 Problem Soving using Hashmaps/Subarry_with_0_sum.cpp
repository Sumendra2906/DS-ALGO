#include <iostream>
#include <unordered_set>
using namespace std;

bool zero_sum(int n, int arr[])
{
    unordered_set<int> s;
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        //check if it is already in the set or if it is 0
        if (pre == 0 or s.find(pre) != s.end())
        {
            return true;
        }
        s.insert(pre);
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << zero_sum(n, arr);
    return 0;
}