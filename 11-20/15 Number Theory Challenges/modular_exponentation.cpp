#include <iostream>
using namespace std;
#define ll unsigned long long

ll power(ll a, ll b, ll c)
{
    if (b == 1)
    {
        return (a % c);
    }
    ll temp = power(a, b / 2, c);
    temp = temp % c;
    temp = (temp * temp) % c;
    if (b % 2 == 0)
    {
        return temp;
    }
    else
    {
        return (temp * (a % c) % c);
    }
}

long long powerOptimized(long long a, long long n, long long m)
{
    long long int ans = 1;
    while (n)
    {
        int last = n & 1;
        if (last)
        {
            ans *= (a % m);
        }
        a = ((a % m) * (a % m)) % m;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    cout << power(a, b, c);
    return 0;
}