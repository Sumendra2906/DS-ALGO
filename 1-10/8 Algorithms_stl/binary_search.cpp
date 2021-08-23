#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int ar[] = {15, 18, 30, 45, 69, 69, 69, 69, 96, 785, 88585};
    int n = sizeof(ar) / sizeof(int);
    int key;
    cin >> key;
    bool present = binary_search(ar, ar + n, key);
    if (present)
    {
        cout << key << " is present." << endl;
    }
    else
    {
        cout << key << " is absent." << endl;
    }

    //lower_bound function returns the address of the  first value >=key
    auto lb = lower_bound(ar, ar + n, key);
    cout << "lb  is " << (lb - ar) << endl;
    //upper_bound function returns the address of the first value >key
    auto ub = upper_bound(ar, ar + n, key);
    cout << "ub  is " << (ub - ar) << endl;

    cout << "Frequency of " << key << " is " << ub - lb;
    return 0;
}