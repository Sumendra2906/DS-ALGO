#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<ll> sieve_prime(int *p, int n)
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
    p[2] = 1;
    p[0] = p[1] = 0;
    primes.push_back(2);
    for (ll i = 3; i <= n; i += 2)
    {
        if (p[i] == 1)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

int main()
{
    int t;
    cin >> t;
    int p[1000005] = {0};
    vector<ll> primes = sieve_prime(p, 1000005);
    while (t)
    {
        t--;
        int n;
        cin >> n;
        cout << primes[n - 1] << endl;
    }
    return 0;
}