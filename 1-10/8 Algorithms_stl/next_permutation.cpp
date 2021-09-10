#include <iostream>
#include <algorithm>
using namespace std;

void nextperm(int *&ar, int n)
{
    //find an index such that a[i]<a[i+1]
    int i;
    for (i = n - 2; i >= 0; i--)
    {
        if (ar[i] < ar[i + 1])
        {
            break;
        }
    }
    if (i < 0)
    {
        reverse(ar, ar+n);
        return;
    }
    //now we need to find j
    //a[j] should be the next greater element
    //smallest element from the right
    int j = n - 1;
    while (j >= i + 1)
    {
        if (ar[j] > ar[i])
        {
            break;
        }
        j--;
    }
    swap(ar[i], ar[j]);
    reverse(ar+ i+1, ar+n);
}

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int n;
        cin >> n;
        int *ar = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        nextperm(ar,n);
        for (int i = 0; i < n; i++)
        {
            cout << ar[i] << " ";
        }
        cout << endl;
        delete[] ar;
    }
}