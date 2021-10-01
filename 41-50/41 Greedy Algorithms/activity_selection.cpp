#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int t, n, s, e;
    vector<pair<int, int>> v;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> e;
            v.push_back(make_pair(s, e));
        }
        sort(v.begin(), v.end(), compare);
        int cnt = 1;
        int temp = v[0].second;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].first >= temp)
            {
                cnt++;
                temp = v[i].second;
            }
        }
        cout << cnt;
        v.clear();
    }
    return 0;
}