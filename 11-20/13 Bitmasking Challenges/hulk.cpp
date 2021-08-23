#include <iostream>
using namespace std;

int count_bits(int n)
{
    int ans = 0;
    while (n)
    {
        ans++;
        n = n & (n - 1);
    }
    return ans;
}

int main()
{
    int t,n;
    cin >> t;
    while (t)
    {
        t--;
        cin >> n;
        cout << count_bits(n) << endl;
    }
    return 0;
}