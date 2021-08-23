#include <iostream>
using namespace std;

int main()
{
    int n, ar[1000], csum = 0, maxsum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                csum = csum + ar[k];
            }
            maxsum = max(maxsum, csum);
            csum = 0;
        }
    }
    cout << maxsum;

    return 0;
}