#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int n, ar[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    sort(ar, ar + n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}