#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, t, rank;
    string s;
    cin >> t;
    int arr[10000] = {0};
    while (t--)
    {
        cin >> n;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            cin >> s >> rank;
            arr[rank]++;
        }
        //now greedy approach
        int bad = 0;
        int actual_rank = 1;
        for (int i = 1; i <= n; i++)
        {
            while (arr[i])
            {
                bad += abs(actual_rank - i);
                arr[i]--;
                actual_rank++;
            }
        }
        cout << bad << endl;
    }
    return 0;
}