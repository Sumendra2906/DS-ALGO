#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
    //we compare ab  and ab
    string ab = a.append(b);
    string ba = b.append(a);
    return ab > ba;
}

int main()
{
    int t;
    cin >> t;
    int n;
    while (t > 0)
    {
        t--;
        cin >> n;
        string *ar = new string[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        sort(ar, ar + n, compare);
        for (int i = 0; i < n; i++)
        {
            cout << ar[i];
        }
        cout << endl;
        delete[] ar;
    }
    return 0;
}