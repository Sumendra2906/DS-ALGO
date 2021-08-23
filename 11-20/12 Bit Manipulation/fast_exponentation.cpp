#include <iostream>
using namespace std;

long long int powerOptimized(int a, int n)
{
    long long int ans = 1;
    while (n)
    {
        int last = n & 1;
        if (last)
        {
            ans *= a;
        }
        a = a * a;
        n = n >> 1;
    }
    return ans;
}

long long int recursivepower(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    long long int num = recursivepower(a, n / 2);
    if (n & 1)
    {
        return num * num * a;
    }
    return num * num;
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << powerOptimized(a, n) << endl;
    cout << recursivepower(a, n);
    return 0;
}