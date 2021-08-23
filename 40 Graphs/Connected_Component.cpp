#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool> &visited)
    {
        //Recursive function that will traverse the graph
        cout << src << " ";
        visited[src] = true;
        //go to all neighbors that are unvisited
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs()
    {
        //maintain a visited map
        map<T, bool> visited;
        //mark all as unvisited
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        //Interate over all the nodes and initite a dfs call if a node is not visited
        int cnt = 0;
        for (auto p : l)
        {
            T node = p.first;
            if (!visited[node])
            {
                cnt++;
                cout <<"Component "<<cnt<<"--> ";
                dfs_helper(node, visited);
                cout << endl;
            }
            
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(4,0);
    g.addEdge(5,6);
    g.addEdge(6,7);

    g.dfs();
    return 0;
}