#include <iostream>
#include <climits>
using namespace std;

void counting_sort(int n, int *ar)
{
    int output[n];
    int maxim = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxim = max(maxim, ar[i]);
    }
    int count[maxim + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        count[ar[i]]++;
    }
    for (int i = 0; i < maxim; i++)
    {
        count[i + 1] += count[i];
    }
    for (int i = 0; i < n; i++)
    {
        output[count[ar[i]] - 1] = ar[i];
        count[ar[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        ar[i] = output[i];
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
    counting_sort(n, ar);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    delete[] ar;
    return 0;
}