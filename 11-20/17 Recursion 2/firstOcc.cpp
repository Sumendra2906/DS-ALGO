#include <iostream>
using namespace std;

int firstOccr(int *arr, int n, int key)
{
    if (n == 0)
        return -1;
    if (arr[0] == key)
        return 0;
    int i = firstOccr(arr + 1, n - 1, key);
    if (i == -1)
        return -1;
    return i + 1;
}

//different style of writing the same function
//for loop to recursion
int linearSearch(int *arr, int i, int n, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return linearSearch(arr, i + 1, n, key);
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
    cout << firstOccr(arr, n, key);
    return 0;
}