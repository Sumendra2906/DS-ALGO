#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
typedef pair<int, int> num;

class Comp
{
public:
    bool operator()(num a, num b)
    {
        //first will store the number and second will store the frequency
        if (a.second == b.second)
        {
            // we want low to high
            return a.first > b.first;
        }
        return a.second < b.second;
        //we want high to low
    }
};

void most_frequent()
{
    int n, k;
    cin >> n >> k;
    priority_queue<num, vector<num>, Comp> pq;
    int arr[10000];
    int count[100] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        count[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        //pushing into the queue
        num temp = make_pair(arr[i], count[arr[i]]);
        pq.push(temp);
    }
    for (int i = 0; i < n; i++)
    {
        while (!pq.empty() and k--)
        {
            cout << pq.top().first << " ";
            int f = pq.top().second;
            //removing elements
            while (f--)
            {
                pq.pop();
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        most_frequent();
    }
    return 0;
}