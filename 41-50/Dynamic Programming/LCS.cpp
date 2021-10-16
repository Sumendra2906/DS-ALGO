#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    //base case
    if (i == s1.length() or j == s2.length())
    {
        return 0;
    }
    //checking
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    //recursive case
    int ans = 0;
    if (s1[i] == s2[i])
    {
        dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);
        return dp[i][j];
    }
    dp[i][j] = max(lcs(s1, s2, i + 1, j, dp), lcs(s1, s2, i, j + 1, dp));
    return dp[i][j];
}

int main()
{
    string s1 = "ABCD";
    string s2 = "ABEDG";
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    //n1 rows n2 columns initialized with -1
    cout << lcs(s1, s2, 0, 0,dp);
    return 0;
}