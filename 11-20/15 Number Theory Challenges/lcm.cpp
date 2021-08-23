#include <iostream>
#define ll long long
using namespace std;

int gcd(ll a, ll b)
{
    //return a if b=0 or else return gcd(b,a%b)
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ll a, b, lcm;
    cin >> a >> b;
    lcm = (a * b) / gcd(a, b);
    cout << lcm;
    return 0;
}