#include <iostream>
using namespace std;

int main()
{
    int n, ar[1000];
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
                cout << ar[k] << ",";
            }
            cout << endl;
        }
    }

    return 0;
}