#include <iostream>
using namespace std;

void lineartime_sort(int n, int *ar)
{
    int left, mid, high;
    left = 0, mid = 0;
    high = n - 1;
    while (mid <= high)
    {
        if (ar[mid] == 0)
        {
            swap(ar[left], ar[mid]);
            mid++;
            left++;
        }
        else if (ar[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(ar[mid], ar[high]);
            high--;
        }
    }
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
    lineartime_sort(n, ar);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << endl;
    }
    delete[] ar;
    return 0;
}