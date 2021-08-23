#include <iostream>
using namespace std;

int tile(int n, int m)
{
    if (n < m)
    {
        return 1;
    }
    if (n == m)
    {
        return 2;
    }
    return tile(n - m, m) + tile(n - 1, m);
}

int main()
{
    int t;
    cin >> t;
    long long n, m;
    while (t--)
    {
        cin >> n >> m;
        cout << tile(n, m) << endl;
    }
    return 0;
}