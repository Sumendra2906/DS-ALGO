#include <iostream>
using namespace std;

int firstOccurence(int *ar, int n, int key)
{
    int s = 0, e = n - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (ar[mid] == key)
        {
            e = mid - 1;
            ans = mid;
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
    return ans;
}

int lastOccurence(int *ar, int n, int key)
{
    int s = 0, e = n - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (ar[mid] == key)
        {
            s = mid + 1;
            ans = mid;
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
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int q;
    cin >> q;
    while (q)
    {
        q--;
        int key;
        cin >> key;
        cout << firstOccurence(ar, n, key) << " ";
        cout << lastOccurence(ar, n, key) << endl;
    }
    delete[] ar;
    return 0;
}