#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<ll> sieve_prime(int *p, ll n)
{
    //mark all odd numbers as prime
    vector<ll> primes;
    for (ll i = 3; i <= n; i += 2)
    {
        p[i] = 1;
    }

    for (ll i = 3; i <= n; i += 2)
    {
        if (p[i] == 1)
        {
            //now mark all  of its multiples  as  non prime
            for (ll j = i * i; j <= n; j += i)
            {
                p[j] = 0;
            }
        }
    }
    //corner cases
    p[0] = p[1] = 0;
    p[2] = 1;
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (p[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

int main()
{
    ll n;
    cin >> n;
    int p[1000005] = {0};
    vector<ll> primes = sieve_prime(p, 1000005);
    cout << primes[i + 1];
    return 0;
}