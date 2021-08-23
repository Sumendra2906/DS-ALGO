#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> q1;
    queue<int> q2;
    int time = 0;
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        q1.push(data);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        q2.push(data);
    }
    while (!q1.empty())
    {
        if (q1.front() == q2.front())
        {
            time++;
            q1.pop();
            q2.pop();
        }
        else
        {
            data = q1.front();
            q1.pop();
            q1.push(data);
            time++;
        }
    }
    cout << time;
}