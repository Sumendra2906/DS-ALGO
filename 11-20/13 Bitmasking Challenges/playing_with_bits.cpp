#include <iostream>
using namespace std;

int countbits(int a, int b)
{
    int res = 0;
    for (int i = a; i <= b; i++)
    {
        int j = i;
        while (j)
        {
            j = j & (j - 1);
            res++;
        }
    }
    return res;
}

int main()
{
    int q;
    cin >> q;
    while (q)
    {
        int a, b;
        q--;
        cin >> a >> b;
        cout << countbits(a, b) << endl;
    }
    return 0;
}