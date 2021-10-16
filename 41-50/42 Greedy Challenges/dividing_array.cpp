#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int t, n;
    int arr[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n, compare);
        int i = 0;
        int j = n - 1;
        int maximum = 0;
        int minimum = 0;
        while (i < j)
        {
            maximum += abs(arr[i] - arr[j]);
            i++;
            j--;
        }
        i = 0;
        while (i < n - 1)
        {
            minimum += abs(arr[i] - arr[i + 1]);
            i += 2;
        }
        cout << minimum << " " << maximum << endl;
    }
    return 0;
}