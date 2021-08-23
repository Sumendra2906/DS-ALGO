#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    while (n--)
    {
        int q_type, x, y;
        cin >> q_type;
        if (q_type == 1)
        {
            cin >> x >> y;
            int dist = x * x + y * y;
            if (pq.size() < k)
            {
                pq.push(dist);
            }
            else if(pq.size()==k and dist<pq.top()){
                pq.pop();
                pq.push(dist);
            }
        }
        else
        {
            cout << pq.top() << endl;
            //pq.pop();
        }
    }

    return 0;
}