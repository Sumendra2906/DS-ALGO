#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count[64] = {0};
    int no;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        cin >> no;
        while (no)
        {
            count[j] += (no & 1);
            j++;
            no = no >> 1;
        }
    }

    //now  take  mod and convert to decimal
    int p = 1;
    int ans = 0;
    for (int i = 0; i < 64; i++)
    {
        ans += ((count[i] % 3) * p);
        p = p << 1;
    }
    cout << ans << endl;
    return 0;
}