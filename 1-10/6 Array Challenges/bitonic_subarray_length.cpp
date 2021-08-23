#include <iostream>
using namespace std;

int len(int n, int *ar)
{
    int inc[n], dec[n];
    inc[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (ar[i] >= ar[i - 1])
        {
            inc[i] = inc[i - 1] + 1;
        }
        else
        {
            inc[i] = 1;
        }
    }
    dec[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (ar[i] >= ar[i + 1])
        {
            dec[i] = dec[i + 1] + 1;
        }
        else
        {
            dec[i] = 1;
        }
    }
    int max = inc[0] + dec[0] - 1;
    for (int i = 1; i < n; i++)
    {
        if (inc[i] + dec[i] - 1 > max)
        {
            max = inc[i] + dec[i] - 1;
        }
    }
    return max;
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
        cout << len(n, ar) << endl;
        delete[] ar;
    }
    return 0;
}