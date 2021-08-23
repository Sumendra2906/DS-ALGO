#include <iostream>
using namespace std;

long long powerOptimized(long long a, long long n)
{
    long long int ans = 1;
    while (n)
    {
        int last = n & 1;
        if (last)
        {
            ans *= a;
        }
        a = a * a;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans = ((powerOptimized(a, b / 2) % c) * (powerOptimized(a, b / 2)) % c) % c;
    if (n & 1)
    {
        cout << ans * (a % c) % c << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}