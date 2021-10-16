#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    //sorting based on the end
    return a.second < b.second;
}

int main()
{
    int ans = 0;
    int n, c, r;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> r;
        v.push_back(make_pair(c - r, c + r));
    }
    sort(v.begin(), v.end(), compare);
    int end = v[0].second;
    int i = 1;
    while (i < n)
    {
        if (v[i].first < end)
        {
            //remove it
            ans++;
            i++;
        }
        else
        {
            end = v[i].second;
            i++;
        }
    }
    cout << ans << endl;
}