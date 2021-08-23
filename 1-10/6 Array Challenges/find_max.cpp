#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    long long m = LONG_MIN;
    cin >> n;
    long long ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        m = max(m, ar[i]);
    }
    cout << m;
    return 0;
}