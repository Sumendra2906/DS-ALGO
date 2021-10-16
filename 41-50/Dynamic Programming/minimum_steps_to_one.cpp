#include <iostream>
using namespace std;

//bottom up approach
int steps_bottom_up(int n)
{
    int dp[1000];
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i % 6 == 0)
            dp[i] = 1 + min(dp[i / 3], min(dp[i / 2], dp[i - 1]));
        else if (i % 2 == 0)
            dp[i] = 1 + min(dp[i / 2], dp[i - 1]);
        else if (i % 3 == 0)
            dp[i] = 1 + min(dp[i / 3], dp[i - 1]);
        else
            dp[i] = 1 + dp[i - 1];
    }
    return dp[n];
}

//top down approach
int steps_top_down(int n, int *dp)
{
    if (dp[n] != 0 or n == 1)
    {
        return dp[n];
    }
    if (n % 6 == 0)
        dp[n] = 1 + min(steps_top_down(n / 3, dp), min(steps_top_down(n / 2, dp), steps_top_down(n - 1, dp)));
    else if (n % 2 == 0)
        dp[n] = 1 + min(steps_top_down(n / 2, dp), steps_top_down(n - 1, dp));
    else if (n % 3 == 0)
        dp[n] = 1 + min(steps_top_down(n / 3, dp), steps_top_down(n - 1, dp));
    else
        dp[n] = 1 + steps_top_down(n - 1, dp);
    return dp[n];
}

int main()
{
    int n;
    int dp[1000] = {0};
    cin >> n;
    cout << steps_bottom_up(n) << endl;
    cout << steps_top_down(n, dp) << endl;
    return 0;
}