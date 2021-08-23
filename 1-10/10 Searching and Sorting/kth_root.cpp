#include <iostream>
using namespace std;
#define ll unsigned long long

ll power(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    ll temp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return temp * temp;
    }
    return temp * temp * x;
}

ll kthroot(ll k, ll n)
{
    ll start = 0;
    ll end = 10000;
    ll ans = -1;
    if (k == 1)
    {
        return n;
    }
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        ll temp = power(mid, k);
        if (temp == n)
        {
            return mid;
        }
        if (temp < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        ll k, n;
        cin >> n >> k;
        cout << kthroot(k, n) << endl;
    }
    return 0;
}