#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void cb_numbers(int n, string s)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            string sub = s.substr(i, j);
        }
    }
}

bool check_prime(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int num = (s[i] - '0');
        n = n * 10 + num;
    }
    if (n <= 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i+=2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << check_prime(s);
    return 0;
}