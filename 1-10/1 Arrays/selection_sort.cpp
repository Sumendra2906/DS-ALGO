#include <iostream>
using namespace std;

//Find the index of minumum element and then swap
void selection_sort(int ar[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idxmin = i;
        for (int j = i; j < n; j++)
        {
            if (ar[j] < ar[idxmin])
            {
                idxmin = j;
            }
        }
        swap(ar[idxmin], ar[i]);
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
    selection_sort(ar, n);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}