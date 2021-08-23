#include <iostream>
using namespace std;

int profit(int n, int c, int *wt, int *prices)
{
    //base case
    if (c == 0 or n == 0)
    {
        return 0;
    }
    int ans = 0;
    int inc, exc;
    inc = 0;
    exc = 0;
        //recursive case
        //inluding last item
        if (c >= wt[n - 1])
    {
        inc = prices[n - 1] + profit(n - 1, c - wt[n - 1], wt, prices);
    }
    //leaving last item
    exc = profit(n - 1, c, wt, prices);
    ans = max(inc, exc);
    return ans;
}

int main()
{
    int n = 4;
    int wt[] = {1, 2, 3, 5};
    int prices[] = {40, 20, 30, 100};
    int capacity;
    cin >> capacity;
    cout << profit(n, capacity, wt, prices);
    return 0;
}