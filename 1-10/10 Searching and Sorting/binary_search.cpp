#include <iostream>
using namespace std;

int binary_search(int n, int *ar, int key)
{
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (ar[mid] == key)
        {
            return mid;
        }
        else if (ar[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, key;
    cin >> n;
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cin >> key;
    cout << binary_search(n, ar, key);
    delete[] ar;
    return 0;
}