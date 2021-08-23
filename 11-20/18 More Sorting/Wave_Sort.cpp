#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ar[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    //Wave  Sort
    for (int i = 0; i < n; i += 2)
    {
        //checkinng with previous element
        //we want to create a peak here
        if (i != 0 and ar[i] < ar[i - 1])
        {
            swap(ar[i], ar[i - 1]);
        }
        //next element
        if (i != n - 1 and ar[i] < ar[i + 1])
        {
            swap(ar[i], ar[i + 1]);
        }
    }
    //printing
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}