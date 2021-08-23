#include <iostream>
using namespace std;

int countbits(int n)
{
    //bruteforce
    int ans = 0;
    while (n)
    {
        int last = n & 1;
        ans = ans + last;
        n = n >> 1;
    }
    return ans;
}

int countbitsFast(int n)
{
    int ans = 0;
    while (n)
    {
        n = n & (n - 1);
        ans++;
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
        int n;
        cin >> n;
        cout << countbitsFast(n) << endl;
    }

    //cout << countbits(n) << endl;
    //cout << __builtin_popcount(n) << endl;
    return 0;
}