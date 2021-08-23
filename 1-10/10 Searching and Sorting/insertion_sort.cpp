#include <iostream>
using namespace std;

void insertion_sort(int n, int *ar)
{
    int key;
    for (int i = 1; i < n; i++)
    {
        key = ar[i];
        int j = i - 1;
        while (j >= 0 and ar[j] > key)
        {
            ar[j + 1] = ar[j];
            j = j - 1;
        }
        ar[j + 1] = key;
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
    insertion_sort(n, ar);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    delete[] ar;
    return 0;
}