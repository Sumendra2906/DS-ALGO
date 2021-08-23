#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<char> q;
    char ch;
    cin >> ch;
    int freq[27];
    while (ch != '.')
    {
        q.push(ch);
        freq[ch - 'a']++;
        while (!q.empty())
        {
            int idx = q.front() - 'a';
            if (freq[idx] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << " ";
                break;
            }
        }
        //q is empty
        if (q.empty())
        {
            cout << -1 << " ";
        }
        cin >> ch;
    }
    return 0;
}