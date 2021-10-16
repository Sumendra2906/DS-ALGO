#include <iostream>
using namespace std;

int rod_top_down(int n, int prices[], int dp[])
{
    //base case
    if (n <= 1)
    {
        return prices[n];
    }
    //lookup
    if (dp[n] != 0)
    {
        return dp[n];
    }
    //recursive case
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int current_ans = prices[i] + rod_top_down(n - i, prices, dp);
        ans = max(current_ans, ans);
    }
    dp[n] = ans;
    return dp[n];
}

int rod_bottom_up(int n, int prices[])
{
    int dp[1000] = {0};
    dp[1] = prices[1];
    for (int i = 2; i <= n; i++)
    {
        int ans = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            int curr = prices[j] + dp[i - j];
            ans = max(curr, ans);
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int prices[1000];
    int dp[1000] = {0};
    prices[0] = 0;
    for (int i = 1; i <= n; i++)
    {

        cin >> prices[i];
    }
    cout << rod_top_down(n, prices, dp) << endl;
    cout << rod_bottom_up(n, prices);
    return 0;
}