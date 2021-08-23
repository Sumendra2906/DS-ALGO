#include <iostream>
#include <algorithm>
using namespace std;

bool place_cows(int *stalls, int n, int c, int min_d)
{
    int cnt = 1;
    int last_cow = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last_cow >= min_d)
        {
            last_cow = stalls[i];
            cnt++;
            if (cnt == c)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, c;
    int ans = 0;
    cin >> n >> c;
    int *stalls = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }
    sort(stalls, stalls + n);
    int s = 0;
    int e = stalls[n - 1] - stalls[0];
    while (s <= e)
    {
        int mid = (s + e) / 2;
        bool cowsrakhpaye = place_cows(stalls, n, c, mid);
        if (cowsrakhpaye)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    delete[] stalls;
    cout << ans << endl;

    return 0;
}