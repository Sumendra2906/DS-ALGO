#include <iostream>
using namespace std;

int power(int a, int n)
{
    if (n == 0)
        return 1;
    int ans = power(a, n / 2);
    if (n & 1)
        return ans * ans * a;
    else
        return ans * ans;
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << power(a, n);
    return 0;
}