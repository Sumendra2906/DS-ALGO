#include <iostream>
using namespace std;

int maxpr(int i, int j, int *p, int y, int dp[][100])
{
    //base case
    //no bottles are left
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }
    //recursive case
    //sell the ith bottle
    int op1 = p[i] * y + maxpr(i + 1, j, p, y + 1,dp);
    //sell the last bottle
    int op2 = p[j] * y + maxpr(i, j - 1, p, y + 1,dp);
    dp[i][j] = max(op1, op2);
    return dp[i][j];
}

int main()
{
    int n;
    cin >> n;
    int pr[1000] = {0};
    int dp[100][100];
    for (int i = 0; i < n; i++)
    {
        cin >> pr[i];
    }
    cout << maxpr(0, n - 1, pr, 1,dp);
    return 0;
}