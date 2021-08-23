#include <iostream>
//#include <algorithm>
using namespace std;

bool possible(int k, int n, int ar[], int time)
{
    int painterUsed = 1;
    int time_taken = 0;
    for (int i = 0; i < n; i++)
    {
        if (time_taken + ar[i] > time)
        {
            painterUsed += 1;
            time_taken = ar[i];
            if (painterUsed > k or time_taken>time)
            {
                return false;
            }
        }
        else
        {
            time_taken += ar[i];
        }
    }
    return true;
}

int paint(int k, int n, int ar[])
{
    int s = ar[n-1];
    int sum = 0, ans;
    for (int i = 0; i < n; i++)
    {
        sum += ar[i];
    }
    int e = sum;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (possible(k, n, ar, mid))
        {
            //try to decrease time
            ans = mid;
            e = mid - 1;
        }
        else
        {
            //increase time
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int k, n;
    cin >> k >> n;
    int ar[100];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    //sort(ar,ar+n);
    cout << paint(k, n, ar);
    return 0;
}