#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int n;
        bool flag = true;
        cin >> n;
        int *ar = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (ar[i-1] < ar[i])
            {
                swap(ar[i], ar[i - 1]);
                flag = false;
                break;
            }
        }

        if(flag){
            sort(ar,ar+n);
        }

        for (int i = 0; i < n; i++)
        {
            cout << ar[i] << " ";
        }
        cout << endl;
        delete[] ar;
    }
}