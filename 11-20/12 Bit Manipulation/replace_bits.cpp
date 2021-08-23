#include <iostream>
using namespace std;

int rangejtoiofbits(int n, int i, int j)
{
    int a = (-1) << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}

int replacebits(int n, int m, int i, int j)
{
    int n_ = rangejtoiofbits(n, i, j);
    int ans = n_ | (m << i);
    return ans;
}

int main()
{
    int n = 15;
    int m = 2;
    int i = 1;
    int j = 3;
    cout << replacebits(n, m, i, j) << endl;
    return 0;
}