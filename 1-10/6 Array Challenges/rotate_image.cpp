#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
        }
    }
    //First Reverse Each Row
    for (int i = 0; i < n; i++)
    {
        reverse(ar[i], ar[i] + n);
    }
    //Take Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(ar[i][j], ar[j][i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}