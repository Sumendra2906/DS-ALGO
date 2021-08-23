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
    int n;
    cin >> n;
    int p[100000] = {0};
    cout << n << endl;
    sieve_prime(p, n);
    for (int i = 0; i <= n; i++)
    {
        if (p[i] == 1)
        {
            cout << i << " ";
        }
    }
    return 0;
}