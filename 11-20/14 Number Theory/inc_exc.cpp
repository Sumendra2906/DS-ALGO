#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll t;
    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    cin >> t;
    while (t)
    {
        t--;
        ll n;
        cin >> n;
        ll ans = 0;
        ll subsets = (1 << 8) - 1;
        //here we will have 2^8-1 subsets
        for (int i = 1; i <= subsets; i++)
        {
            ll denom = 1;
            //count the number of set bits
            ll set_bits = __builtin_popcount(i);
            for (int j = 0; j <= 7; j++)
            {
                if (i & (1 << j))
                { //bit is set
                    denom *= primes[j];
                }
            }
            if (set_bits & 1)
            {
                ans += (n / denom);
            }
            else
            {
                ans -= (n / denom);
            }
        }
        cout << ans << endl;
    }
    return 0;
}