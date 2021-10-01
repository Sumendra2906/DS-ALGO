#include <iostream>
using namespace std;

int main()
{
    int n, load;
    int arr[10000];
    while (true)
    {
        cin >> n;
        if (n == -1)
        {
            break;
        }
        else
        {
            load=0;
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
                load += arr[i];
            }
        }
        if (load % n != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            load = load/n;
            //we will maintain a running difference
            int diff = 0;
            int max_load = 0;
            for (int i = 0; i < n; i++)
            {
                //make partiuons and maintain the running difference
                diff += (arr[i] - load);
                int ans = abs(diff);
                max_load = max(max_load, ans);
            }
            cout << max_load << endl;
        }
    }
    return 0;
}