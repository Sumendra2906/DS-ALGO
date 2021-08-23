#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

/*in p we are storing occurences of (commulative sum%n)  like 1 occurence of 0 and like this */

int main()
{
    ll p[10000], a[10000];
    int t, n;
    cin >> t;
    while (t)
    {
        t--;
        memset(p, 0, sizeof(p));
        p[0] = 1;
        //because in the begining the sum  will be 0
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum = sum + a[i];
            sum = (sum + n) % n;
            //doing sum+n so that we don't  get it as negative
            p[sum]++;
        }
        ll ans = 0;
        //doing Mc2
        for (int i = 0; i < n; i++)
        {
            ll m = p[i];
            ans = ans + (m * (m - 1)) / 2;
        }
        cout << ans << endl;
    }
}