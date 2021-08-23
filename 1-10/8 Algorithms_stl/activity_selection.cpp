#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int n;
        cin >> n;
        vector<pair<int, int>> vect;
        int st;
        int et;
        for (int i = 0; i < n; i++)
        {
            cin >> st >> et;
            vect.push_back(make_pair(st, et));
        }

        sort(vect.begin(), vect.end(), compare);

        int act = 1;
        et = vect[0].second;
        for (int i = 1; i < n; i++)
        {
            if (vect[i].first >= et)
            {
                act++;
                et = vect[i].second;
            }
        }
        cout << act << endl;
    }
}