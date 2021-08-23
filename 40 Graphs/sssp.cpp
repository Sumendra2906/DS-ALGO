#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>
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

    void bfs(T src)
    {
        //we are storing distance
        map<T, int> distance;
        queue<T> q;
        //all other nodes will have distance as int_max
        for (auto node_pair : l)
        {
            //it will give key value pair
            T key = node_pair.first;
            distance[key] = INT_MAX;
        }
        q.push(src);
        distance[src] = 0;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            //find neighbors
            for (auto nbr : l[node])
            {
                if (distance[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    distance[nbr] = distance[node] + 1;
                }
            }
        }
        //print distance to every node
        for (auto node_pair : l)
        {
            T key = node_pair.first;
            cout << key << " " << distance[key] << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfs(0);
    return 0;
}