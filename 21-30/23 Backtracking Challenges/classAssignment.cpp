#include <iostream>
using namespace std;

int numbers(int n)
{
    //base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 3;
    }
    //recursive case
    return numbers(n - 1) + numbers(n - 2);
}

int main()
{
    int t,n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << numbers(n);
    }
    return 0;
}