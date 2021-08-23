#include <iostream>
using namespace std;

int main()
{
    int n, ar[1000], cs = 0, ms = 0, ts;
    cin >> n;
    int i = 0, j = n - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cin >> ts;
    while (j > i)
    {
        if (ar[i] + ar[j] > ts)
        {
            j--;
        }
        else if (ar[i] + ar[j] < ts)
        {
            i++;
        }
        else
        {
            cout << i << " " << j << endl;
            i++;
            j--;
        }
    }
    return 0;
}