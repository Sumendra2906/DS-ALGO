#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int xoy = x ^ y;
    int count = 0;
    //find msb
    while (xoy)
    {
        count++;
        xoy = xoy >> 1;
    }
    //now count is the position of msb so find the number
    int p = 1;
    int ans = 0;
    while (count)
    {
        count--;
        ans = ans + p;
        p = p << 1;
    }

    cout << ans << endl;

    return 0;
}