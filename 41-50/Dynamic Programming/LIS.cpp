#include <iostream>
#include <algorithm>
using namespace std;

int upper_bound_cstm(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] < key and arr[mid + 1] > key)
        {
            return mid+1;
        }
        if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int lis(int n, int arr[])
{
    int dp[10000] = {0};
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1; // every element can end at itself
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    //now check for maximum in the dp array
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(dp[i], ans);
    }
    return ans;
}

int lis2(int n, int arr[])
{
    int dp[1000];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        //iterating over all the elements and finding a good position for them
        for (int j = 1; j < n + 1; j++)
        {
            if (dp[j - 1] < arr[i] and dp[j] > arr[i])
            {
                dp[j] = arr[i];
            }
        }
    }
    //now find the maximum other than 1e9
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
        if (dp[i] != INT_MAX)
            ans = max(ans, i);
    }
    cout << endl;
    return ans;
}

int lis3(int n, int arr[])
{
    int dp[1000];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        //iterating over all the elements and finding a good position for them
        int temp = upper_bound_cstm(dp, n + 1, arr[i]);
        dp[temp] = arr[i];
    }
    //now find the maximum other than 1e9
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
        if (dp[i] != INT_MAX)
            ans = max(ans, i);
    }
    cout << endl;
    return ans;
}

int main()
{
    int n;
    int arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << lis3(n, arr);
    return 0;
}