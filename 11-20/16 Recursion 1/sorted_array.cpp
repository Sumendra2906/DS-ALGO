#include <iostream>
using namespace std;

bool isSorted(long long *arr, int n)
{
    //base case
    if (n == 1)
        return true;
    if (arr[0] <= arr[1] and isSorted(arr + 1, n - 1))
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    long long arr[1005];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (isSorted(arr, n))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}