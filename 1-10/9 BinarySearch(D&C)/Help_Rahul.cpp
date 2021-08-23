#include <iostream>
using namespace std;

int bs(int ar[], int n, int key)
{
    int s = 0, e = n - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (ar[mid] == key)
        {
            return mid;
        }
        else if (ar[s] <= ar[mid])
        {
            //part1
            if (ar[s] <= key and ar[mid] >= key)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            //second part
            if (ar[e] >= key and ar[mid] <= key)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n, key, ar[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cin >> key;
    cout << bs(ar, n, key);
}