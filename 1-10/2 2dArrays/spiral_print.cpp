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
    int sr = 0, er = m - 1, sc = 0, ec = n - 1;
    while (sr <= er and sc <= ec)
    {
        for (int i = sc; i <= ec; i++)
        {
            cout << ar[sr][i] << " ";
        }
        sr++;
        for (int i = sr; i <= er; i++)
        {
            cout << ar[i][ec] << " ";
        }
        ec--;
        if (er > sr)
        {
            for (int i = ec; i >= sc; i--)
            {
                cout << ar[er][i] << " ";
            }
            er--;
        }
        if (ec > sc)
        {
            for (int i = er; i >= sr; i--)
            {
                cout << ar[i][sc] << " ";
            }
            sc++;
        }
    }
}