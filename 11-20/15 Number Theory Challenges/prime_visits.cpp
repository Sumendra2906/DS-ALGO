#include <iostream>
using namespace std;

#define ll long long

void sieve_prime(int *p, int n)
{
    //mark all odd numbers as prime
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
}

int main()
{
    int t;
    cin >> t;
    int p[1000005] = {0};
    sieve_prime(p, 1000005);
    int csum[1000005] = {0};
    for (ll i = 1; i <= 1000005; i++)
    {
        csum[i] = csum[i - 1] + p[i];
    }
    while (t)
    {
        t--;
        int a, b;
        cin >> a >> b;
        cout << csum[b] - csum[a] << endl;
    }
    return 0;
}