#include <iostream>
using namespace std;

//we can also start  from  the right and find the first occurence

int lastOccr(int *arr, int n, int key)
{
    if (n == 0)
        return -1;
    int i = lastOccr(arr + 1, n - 1, key);
    if (i == -1)
    {
        if (arr[0] == key)
            return 0;
        else
            return -1;
    }
    return i + 1;
}

int main()
{
    int n, key;
    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> key;
    cout << lastOccr(arr, n, key);
    return 0;
}