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
        int ms = 0, cs;
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        int st = 0;
        int end, m = 0;
        while (st < n)
        {
            end = st + n;
            cs = 0;
            for (int i = st; i < end; i++)
            {
                ms = 0;
                cs = cs + ar[i % n];
                if (cs < 0)
                {
                    cs = 0;
                }
                ms = max(cs, ms);
            }
            m = max(ms, m);
            st++;
        }
        delete[] ar;
        cout << m << endl;
    }
    return 0;
}