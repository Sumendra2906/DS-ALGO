#include <iostream>
#include <climits>
using namespace std;

bool possible(int p, int n, int r[], int time)
{
    int pratas_made = 0;
    int time_taken = 0;
    int i = 0;
    int p_no=1;
    while (i < n)
    {
        if (time_taken + p_no * r[i] > time)
        {
            i++;
            p_no = 1;
            time_taken=0;
        }
        else
        {
            time_taken += r[i] * p_no;
            pratas_made++;
            p_no++;
        }
    }
    if (pratas_made >= p)
    {
        return true;
    }
    return false;
}

int prata(int p, int n, int r[])
{
    int s = 0;
    int ans = INT_MAX;
    int max_time = 0;
    for (int i = 1; i <= p; i++)
    {
        max_time += r[0] * i;
    }
    int e = max_time;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (possible(p, n, r, mid))
        {
            //try to  decrease time
            ans = min(ans, mid);
            e = mid - 1;
        }
        else
        {
            //not possibe so increase time
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int p, n, r[1000];
        cin >> p;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
        }
        cout << prata(p, n, r) << endl;
    }
    return 0;
}