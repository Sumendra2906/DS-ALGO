#include <iostream>
using namespace std;

void selection_sort(int n, int *ar)
{
    int idx_min;
    for (int i = 0; i < n - 1; i++)
    {
        idx_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ar[j] < ar[idx_min])
            {
                idx_min = j;
            }
        }
        swap(ar[i], ar[idx_min]);
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
    selection_sort(n, ar);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << endl;
    }
    delete[] ar;
    return 0;
}