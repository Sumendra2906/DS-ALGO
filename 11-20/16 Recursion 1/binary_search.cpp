#include <iostream>
using namespace std;

int binarySearch(int *arr, int s, int e, int key)
{
    if (s > e)
        return -1;
    int mid = (s + e) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[mid] < key)
        return binarySearch(arr, mid + 1, e, key);
    else
        return binarySearch(arr, s, mid - 1, key);
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
    cout << binarySearch(arr, 0, n, key);
    return 0;
}