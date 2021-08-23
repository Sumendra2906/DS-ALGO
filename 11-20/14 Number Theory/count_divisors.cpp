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

int divisors(int n, vector<int> primes)
{
    int ans = 1;
    int i = 0;
    int p = primes[0];
    while (p * p <= n)
    {
        if (n % p == 0)
        {
            int cnt = 0;
            
            while (n % p == 0)
            {
                cnt++;
                n = n / p;
            }
            ans = ans * (cnt + 1);
        }
        i++;
        p = primes[i];
    }
    if (n != 1)
    {
        //there is  one factor remaining and it has power 1 so we need to multiply by 2
        ans = ans * 2;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int p[10000] = {0};
    vector<int> primes = sieve_prime(p, 1000);
    cout << divisors(n,primes) << endl;
    return 0;
}