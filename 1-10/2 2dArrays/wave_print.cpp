#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the number of rows and columns" << endl;
    cin >> m;
    cin >> n;
    int ar[100][100] = {0};
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                cout << ar[j][i] << " ";
            }
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                cout << ar[j][i] << " ";
            }
        }
        cout << endl;
    }
}