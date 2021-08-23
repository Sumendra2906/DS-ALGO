#include <iostream>
using namespace std;

int main()
{
    int n, ar[1000], csum = 0, maxsum = 0;
    int cs[1000] = {0};
    cin >> n;
    cin >> ar[0];
    cs[0] = ar[0];
    for (int i = 1; i < n; i++)
    {
        cin >> ar[i];
        cs[i] = cs[i - 1] + ar[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            csum = cs[j] - cs[i - 1];
            maxsum = max(maxsum, csum);
            csum = 0;
        }
    }
    cout << maxsum;

    return 0;
}