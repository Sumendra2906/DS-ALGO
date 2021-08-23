#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//vallue,x,y
typedef pair<int, pair<int, int>> node;

vector<int> merge_k_sorted(vector<vector<int>> arr, int n, int k)
{
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq;
    //initialize the min heap with the first element of each array
    //n colums k rows
    for (int i = 0; i < k; i++)
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
        if (y + 1 < n)
        {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}

int main()
{
    int k, n, temp;
    cin >> k >> n;
    //vector with k vectors
    vector<vector<int>> arr(k);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            arr[i].push_back(temp);
        }
    }
    vector<int> res = merge_k_sorted(arr, n, k);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}