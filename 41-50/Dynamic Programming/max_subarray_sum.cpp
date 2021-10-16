#include <iostream>
using namespace std;

//bottom up
int max_sum(int n, int arr[])
{
    int dp[100] = {0};
    dp[0] = arr[0] > 0 ? arr[0] : 0;
    int max_so_far = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + arr[i];
        if (dp[i] < 0)
            dp[i] = 0;
        max_so_far = max(max_so_far, dp[i]);
    }
    return max_so_far;
}

int max_sum_sp(int n, int arr[])
{
    int max_so_far = 0;
    int cmax = 0;
    for (int i = 0; i < n; i++)
    {
        cmax += arr[i];
        if (cmax < 0)
        {
            cmax = 0;
        }
        max_so_far = max(max_so_far, cmax);
    }
    if (max_so_far == 0)
    {
        //all negative numbers so return the smallest negative number
        max_so_far = arr[0];
        for (int i = 1; i < n; i++)
        {
            max_so_far = max(max_so_far, arr[i]);
        }
    }
    return max_so_far;
}

int main()
{
    int n;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << max_sum_sp(n, arr);
}