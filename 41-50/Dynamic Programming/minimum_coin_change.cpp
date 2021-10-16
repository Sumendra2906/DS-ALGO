#include <iostream>
#include <climits>
using namespace std;

//top down
int min_coin_top(int n, int *dp, int *coins)
{
    //base case
    if (n == 0)
        return 0;
    //lookup
    if (dp[n] != 0)
    {
        return dp[n];
    }
    int mini = INT_MAX;
    int size = sizeof(coins) / sizeof(coins[0]);
    for (int i = 0; i < size; i++)
    {
        if (n >= coins[i])
            mini = min(mini, min_coin_top(n - coins[i], dp, coins));
    }
    dp[n] = mini + 1;
    return dp[n];
}

//bottom up approach
//iterative
int min_coin_bottom_up(int n, int *coins)
{
    int dp[1000] = {0};
    int size = sizeof(coins) / sizeof(coins[0]);
    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        for (int j = 0; j < size; j++)
        {
            if (i >= coins[j])
                mini = min(mini, dp[i - coins[j]]);
        }
        dp[i] = 1 + mini;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int coins[] = {1, 7, 10};
    int dp[100] = {0};
    cout << min_coin_top(n, dp, coins) << endl;
    cout << min_coin_bottom_up(n, coins) << endl;
}