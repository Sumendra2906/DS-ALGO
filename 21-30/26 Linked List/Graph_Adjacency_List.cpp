#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<pair<int, int>> *l;
    int n;
    cin >> n;
    l = new list<pair<int, int>>[n];
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y, wt;
        //edge from x to y with weight wt
        //so we have to add (y,w) in the ith list
        cin >> x >> y >> wt;
        l[x].push_back(make_pair(y, wt));
        //if bidirectional
        l[y].push_back(make_pair(x, wt));
    }
    //print
    for (int i = 0; i < n; i++)
    {
        for (auto xp : l[i])
        {
            cout << "(" << xp.first << ","
                 << xp.second << ")"
                 << "->";
        }
        cout << endl;
    }
    delete[] l;
    return 0;
}