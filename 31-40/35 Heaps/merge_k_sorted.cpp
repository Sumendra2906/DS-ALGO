#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//vallue,x,y
typedef pair<int, pair<int, int>> node;

vector<int> merge_k_sorted(vector<vector<int>> arr)
{
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq;
    //initialize the min heap with the first element of each array
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }
    //remove the elements one by one from the min heap and push into the resultant array
    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;
        int y = current.second.second;

        result.push_back(element);
        //now we have to push the next element
        if (y + 1 < arr[x].size())
        {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> arr{{2, 6, 12, 15},
                            {1, 3, 14, 20},
                            {3, 5, 8, 10}};
    vector<int> res = merge_k_sorted(arr);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}