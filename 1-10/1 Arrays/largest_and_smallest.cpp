#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, a[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxi, mini;
    maxi = INT_MIN;
    mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, a[i]);
        mini = min(mini, a[i]);
    }
    cout << "Maximum is :" << maxi << endl;
    cout << "Minimum is :" << mini << endl;
}