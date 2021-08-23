#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ar[100005];
    int res = 0;
    int no;
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        res = res ^ no;
        ar[i] = no;
    }
    //now find the position of first set bit in res
    int pos = 0;
    int temp = res;
    while ((temp & 1) == 0)
    {
        pos++;
        res = temp >> 1;
    }
    int mask = 1 << pos;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        if ((ar[i] & mask) > 0)
        {
            x = x ^ ar[i];
        }
    }
    y = res ^ x;
    cout << min(x, y) << " " << max(x, y) << endl;
    return 0;
}