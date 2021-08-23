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
    }

    T bfs(T src, T dest)
    {
        //we are storing distance
        map<T, int> distance;
        map<T, T> parent;
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
        parent[src] = src;
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
                    parent[nbr] = node;
                }
            }
        }
        //print path
         T temp = dest;
        while (parent[temp] != src)
        {
            cout << temp << " <- ";
            temp = parent[temp];
        }

        //print distance to every node
        return distance[dest];
    }
};

int main()
{
    int board[50];
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    Graph<int> g;
    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];
            if (j <= 36)
            {
                g.addEdge(i, j);
            }
        }
    }
    g.addEdge(35, 36);
    g.addEdge(36, 36);
    cout << g.bfs(0, 36) << endl;
    return 0;
}