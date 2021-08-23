#include <iostream>
using namespace std;

int staircase(int ar[][35], int m, int n, int num)
{
    int row = 0;
    int col = n - 1;
    while (row < m && col >= 0)
    {
        if (num < ar[row][col])
        {
            col--;
        }
        else if (num == ar[row][col])
        {
            return 1;
        }
        else
        {
            row++;
        }
    }
    return 0;
}

int main()
{
    int m, n, num;
    cin >> m >> n;
    int ar[m][35];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
        }
    }
    cin >> num;
    cout << staircase(ar, m, n, num);
    return 0;
}
