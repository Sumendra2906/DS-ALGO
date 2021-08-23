#include <iostream>
#include <list>
#include <unordered_map>
#include <cstring>
using namespace std;

class Graph
{
    unordered_map<string, list<pair<string, int>>> l;

public:
    void addEdge(string x, string y, bool bi, int w)
    {
        l[x].push_back(make_pair(y, w));
        if (bi)
        {
            l[y].push_back(make_pair(x, w));
        }
    }
    void print()
    {
        for (auto p : l)
        {
            string city = p.first;
            list<pair<string, int>> nbrs = p.second;
            cout << city << " -> ";
            for (auto it : nbrs)
            {
                cout << "(" << it.first << "," << it.second << ")";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 30);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    g.print();
    return 0;
}