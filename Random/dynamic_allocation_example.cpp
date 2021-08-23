#include <iostream>
using namespace std;

int main()
{
    int ar[100] = {0};
    cout << sizeof(ar) << endl;

    //Dynamic Allocation
    int n;
    cin >> n;
    int *a = new int[n]{0};
    //Allocation and initialization
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cout << a[i] << " ";
    }
    cout << sizeof(a) << endl;
    delete[] a;
    return 0;
}
