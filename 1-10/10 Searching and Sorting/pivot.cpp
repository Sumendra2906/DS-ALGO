#include <iostream>
using namespace std;

int pivot(int n, int *ar)
{
    int s = 0;
    int ans;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (ar[mid] > ar[mid + 1])
        {
            return mid;
        }
        else if (ar[mid] >= ar[s])
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
    int n;
    cin >> n;
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << pivot(n, ar);
    delete[] ar;
}