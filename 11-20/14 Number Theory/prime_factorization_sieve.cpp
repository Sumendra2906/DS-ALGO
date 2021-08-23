#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<int> sieve_prime(int *p, int n)
{
    //mark all odd numbers as prime
    vector<int> primes;
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
    for (int i = 3; i <= n; i += 2)
    {
        if (p[i] == 1)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

vector<int> factors(int n, vector<int> primes)
{
    vector<int> fact;
    int i = 0;
    int p = primes[0];
    while (p * p <= n)
    {
        if (n % p == 0)
        {
            fact.push_back(p);
            while (n % p == 0)
            {
                n = n / p;
            }
        }
        i++;
        p = primes[i];
    }
    if (n != 1)
    {
        fact.push_back(n);
    }
    return fact;
}

int main()
{
    int n;
    cin >> n;
    int p[10000] = {0};
    vector<int> primes = sieve_prime(p, 1000);
    vector<int> fact = factors(n, primes);
    for (auto p : fact)
    {
        cout << p << endl;
    }
    return 0;
}