#include <iostream>
//#include <algorithm>
using namespace std;

bool possible(int k, int n, int *ar, int time)
{
    int painterUsed = 1;
    int time_taken = 0;
    for (int i = 0; i < n; i++)
    {
        if (time_taken + ar[i] > time)
        {
            painterUsed += 1;
            time_taken = ar[i];
            if (painterUsed > k or time_taken > time)
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

long long int paint(int k, int n, int *ar, int t)
{
    int s = ar[n - 1];
    long long int sum = 0, ans;
    for (int i = 0; i < n; i++)
    {
        sum += ar[i];
    }
    long long int e = sum;
    while (s <= e)
    {
        long long int mid = (s + e) / 2;
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
    return (ans * t) % 10000003;
}

int main()
{
    int k, n, t;
    cin >> n >> k >> t;
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    //sort(ar,ar+n);
    cout << paint(k, n, ar, t);
    delete[] ar;
    return 0;
}