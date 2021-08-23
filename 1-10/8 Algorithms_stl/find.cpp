#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int ar[] = {15, 58, 5481, 85, 78, 96, 69};
    int n = sizeof(ar) / sizeof(int);
    int key;
    cin >> key;
    auto it = find(ar, ar + n, key);
    int index = it - ar;
    if (index == n)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << index;
    }
    return 0;
}