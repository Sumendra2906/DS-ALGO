#include <iostream>
using namespace std;

void b_sort(int n, int *ar)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                swap(ar[j], ar[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
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
    b_sort(n, ar);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << endl;
    }
    delete[] ar;
    return 0;
}