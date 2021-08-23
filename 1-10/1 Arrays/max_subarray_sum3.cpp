#include <iostream>
using namespace std;

int main()
{
    int n, ar[1000], cs = 0, ms = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    for (int i = 0; i < n; i++)
    {
        cs = cs + ar[i];
        if (cs < 0)
        {
            cs = 0;
        }
        ms = max(ms, cs);
    }
    cout << ms;

    return 0;
}