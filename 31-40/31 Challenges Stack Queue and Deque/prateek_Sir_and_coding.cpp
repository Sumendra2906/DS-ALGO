#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int q;
    int flag;
    int cost;
    cin >> q;
    stack<int> s;
    while (q--)
    {
        cin >> flag;
        if (flag == 1 and !s.empty())
        {
            cout << s.top() << endl;
            s.pop();
        }
        else if (flag == 2)
        {
            cin >> cost;
            s.push(cost);
        }
        else if (s.empty())
        {
            cout << "No Code" << endl;
        }
    }
    return 0;
}