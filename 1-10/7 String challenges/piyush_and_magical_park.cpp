#include <iostream>
using namespace std;

void magicalsqare(int n, int m, int k, int s, char ch[][100])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s < k)
            {
                cout << "No";
                return;
            }
            if (ch[i][j] == '.')
            {
                s -= 2;
            }
            else if (ch[i][j] == '*')
            {
                s += 5;
            }
            else
            {
                break;
            }
            if (j != m - 1)
            {
                s -= 1;
            }
        }
    }
    cout << "Yes" << endl
         << s;
}

int main()
{
    int n, m, k, s, ans;
    cin >> n >> m >> k >> s;
    char ch[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ch[i][j];
        }
    }
    magicalsqare(n, m, k, s, ch);
    return 0;
}