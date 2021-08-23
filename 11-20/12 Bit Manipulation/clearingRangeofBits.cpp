#include <iostream>
using namespace std;

int lastibits(int n, int i)
{
    int mask = (-1) << i;
    return n & mask;
}

int rangejtoiofbits(int n, int i, int j)
{
    int a = (-1) << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}

int main()
{
    int n, i, j;
    cin >> n;
    cin >> i;
    cin >> j;
    cout << lastibits(n, i) << endl;
    cout << rangejtoiofbits(n, i, j);
    return 0;
}