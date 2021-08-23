#include <iostream>
using namespace std;

int power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return a * power(a, n - 1);
}

int fast_power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int small_ans = fast_power(a, n / 2);
    small_ans *= small_ans;
    if (n & 1)
        return small_ans * a;
    return small_ans;
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << power(a, n) << endl;
    cout << fast_power(a, n) << endl;
    return 0;
}