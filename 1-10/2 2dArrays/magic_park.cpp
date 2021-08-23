#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the number of rows and columns" << endl;
    cin >> m;
    cin >> n;
    char ar[100][100];
    int k, s;
    bool win = true;
    cout << "Enter k ";
    cin >> k;
    cout << "Enter s ";
    cin >> s;
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch = ar[i][j];
            if (s < k)
            {
                win = false;
                break;
            }
            if (ch == '#')
            {
                break;
            }
            else if (ch == '.')
            {
                s = s - 2;
            }
            else if (ch == '*')
            {
                s = s + 5;
            }
            if (j != n - 1)
            {
                s = s - 1;
            }
        }
    }
    if (win)
    {
        cout << "YES" << endl;
        cout << s;
    }
    else
    {
        cout << "NO";
    }
}