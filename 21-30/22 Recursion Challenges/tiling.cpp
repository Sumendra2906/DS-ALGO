#include <iostream>
using namespace std;

int tile(int n, int m)
{
    //base case
    if (n < m)
        return 1;
    if (m <= 1)
        return 1;
    return tile(n - 1, m) + tile(n - m, m - 1);
}

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << tile(n, m) << endl;
    }
    return 0;
}