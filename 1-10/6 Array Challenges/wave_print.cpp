#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int ar[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
        }
    }
    bool flag = true;
    for (int j = 0; j < n; j++)
    {
        if (flag)
        {
            for (int i = 0; i < m; i++)
            {
                cout << ar[i][j] << ", ";
            }
            flag = false;
        }
        else
        {
            for (int i = m - 1; i >= 0; i--)
            {
                cout << ar[i][j] << ", ";
            }
            flag = true;
        }
    }
    cout << "END";
    return 0;
}