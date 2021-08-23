#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        t--;
        int n;
        cin >> n;
        int *ar = new int[n];
        int cs = 0, ms = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
            cs = cs + ar[i];
            if (cs < 0)
            {
                cs = 0;
            }
            ms = max(cs, ms);
        }
        delete[] ar;
        cout << ms << endl;
    }
    return 0;
}