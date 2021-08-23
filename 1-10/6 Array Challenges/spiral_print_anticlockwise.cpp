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
    int startRow = 0, endRow = m - 1, endCol = n - 1, startCol = 0;
    while (startRow <= endRow && startCol <= endCol)
    {
        for (int i = startRow; i <= endRow; i++)
        {
            cout << ar[i][startCol] << ", ";
        }
        startCol++;
        for (int i = startCol; i <= endCol; i++)
        {
            cout << ar[endRow][i] << ", ";
        }
        endRow--;
        for (int i = endRow; i >= startRow; i--)
        {
            cout << ar[i][endCol] << ", ";
        }
        endCol--;
        for (int i = endCol; i >= startCol; i--)
        {
            cout << ar[startRow][i] << ", ";
        }
        startRow++;
    }

    return 0;
}