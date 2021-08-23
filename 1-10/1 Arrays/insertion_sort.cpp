#include <iostream>
using namespace std;

void insertion_sort(int ar[], int n)
{
    int e, j;
    for (int i = 1; i <= n - 1; i++)
    {
        e = ar[i];
        j = i - 1;
        while (j >= 0 and ar[j] > e)
        {
            ar[j + 1] = ar[j];
            j = j - 1;
        }
        ar[j + 1] = e;
    }
}

int main()
{
    int n, ar[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    insertion_sort(ar, n);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}