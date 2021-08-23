#include <iostream>
using namespace std;

int ladder(int n,int k)
{
    //base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    int ans = 0;
    //k  is the maximum jump size.
    for (int i = 1; i <= k; i++)
    {
        ans += ladder(n - i, k);
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << ladder(n, k) << endl;
    return 0;
}