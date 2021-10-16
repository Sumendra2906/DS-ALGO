#include <iostream>
using namespace std;

//recursive approach
int fib(int n)
{
    //base case
    if (n == 0 or n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

//top down approach
//recursion+memoisation
int fib_top(int n, int dp[])
{
    //base case
    if (n == 0 or n == 1)
    {
        return n;
    }
    //lookup
    if (dp[n] != 0)
    {
        return dp[n];
    }
    int ans = fib_top(n - 1, dp) + fib_top(n - 2, dp);
    dp[n] = ans;
    return dp[n];
}

//bottomUp Approach
int fib_bottom(int n)
{
    int dp[1000] = {0};
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fib_bottom_space(int n)
{
    //int dp[1000] = {0};
    //dp[1] = 1;
    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int dp[1000] = {0};
    int ans = fib_bottom_space(12);
    cout << ans << endl;
    return 0;
}