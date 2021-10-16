#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t, n;
    int cost[100001];
    int fuel[100001];
    //priority_queue<int, vector<int>, greater<int> pq;

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> cost[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> fuel[i];
        }
        int tot = cost[0] * fuel[0];
        int minn = cost[0];
        int x = 1;
        while (x < n)
        {
            if (minn < cost[x])
            {
                tot += (minn * fuel[x]);
            }
            else
            {
                minn = cost[x];
                tot += (minn * fuel[x]);
            }
            x++;
        }
        cout << tot;
    }
    return 0;
}