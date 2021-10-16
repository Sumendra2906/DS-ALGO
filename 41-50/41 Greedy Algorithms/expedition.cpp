#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool cmpr(pair<int, int> l, pair<int, int> r)
{
    return l.first > r.first;
}
int main()
{
    int n, t, x, d, f, D, F, prev = 0;
    cin >> t;
    while (t--)
    {
        int flag = 0, ans = 0;
        vector<pair<int, int>> v;
        priority_queue<int> pq;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> d >> f;
            //Insert the city index and fuel capacity
            v.push_back(make_pair(d, f));
        }
        //Sort the cities according to their location
        sort(v.begin(), v.end(), cmpr);
        cin >> d >> f;
        //Calculate the difference between the current city and the
        //destination i.e. v[i] = j means that we need to travel j
        //units to rach our destination
        for (int i = 0; i < n; i++)
        {
            v[i].first = D - v[i].first;
        }
        //prev denotes the previous city visited
        prev = 0;
        //x will denote the current city that we are in
        x = 0;
        while (x < n)
        {
            //cout<<x<<" "<<F<<" "<<v[x].first<<" "<<prev<< " " << endl;
            //If we have enough fuel to travel from prev to current city
            //Push this fuel station to priority_queue
            //Reduce the amount of fuel used
            //update the previous city
            if (F >= (v[x].first - prev))
            {
                F -= (v[x].first - prev);
                pq.push(v[x].second);
                prev = v[x].first;
            }
            //If we dont have enough fuel to visit
            //the current city
            //Find the max capacity fuel station between
            //prev and current city and use it to refuel
            else
            {
                //If no fuel station is left
                //i.e. we have used all of
                //the fuel stations and still not able
                //to reach the city
                //return FAIL!
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }
                //Increment the fuel capacity of truck
                //by the maximum fuel station capacity
                F += pq.top();
                //Remove that fuel station from heap
                pq.pop();
                //Increment the number of used fuel
                //station by 1
                ans++;
                continue;
            }
            //If we have visited the current city
            //Visit next city
            x++;
        }
        if (flag)
        {
            cout << -1 << endl;
            continue;
        }
        //Find the distance between the destination
        //and last city
        //Check if it is possible to visit the destination
        //from the last city.
        D = D - v[n - 1].first;
        if (F >= D)
        {
            cout << ans << endl;
            continue;
        }
        while (F < D)
        {
            if (pq.empty())
            {
                flag = 1;
                break;
            }
            F += pq.top();
            pq.pop();
            ans++;
        }
        if (flag)
        {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}