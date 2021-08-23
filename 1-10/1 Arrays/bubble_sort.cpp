#include <iostream>
using namespace std;

//Put Maximum Element at the end

void bubble_sort(int ar[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                swap(ar[j], ar[j + 1]);
            }
        }
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
    bubble_sort(ar, n);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}