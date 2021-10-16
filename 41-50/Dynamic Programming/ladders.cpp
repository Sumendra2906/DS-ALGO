#include <iostream>
using namespace std;

int ladders_topdown(int n, int k, int dp[])
{
    if (n == 0)
    {
        //only one way to stay on the ground
        return 1;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    int ways = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
            ways += ladders_topdown(n - i, k, dp);
    }
    dp[n] = ways;
    return dp[n];
}

int ladders_bottom_up(int n, int k)
{
    int dp[1000];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

//another optimised
int ladders_optimised(int n, int k)
{
    int dp[1000] = {0};
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
        //because n-k-1 will be negative here
    }
    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }
    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int dp[1000] = {0};
    cout << ladders_bottom_up(n, k) << endl;
    cout << ladders_optimised(n, k) << endl;
    return 0;
}