#include <iostream>
#include <string>
using namespace std;

int stringToInt(string a, int n)
{
    //base case
    if (n == 0)
    {
        return 0;
    }
    //recursive case
    int last = a[n - 1] - '0';
    int small_ans = stringToInt(a, n - 1);
    return small_ans * 10 + last;
}

int main()
{
    string a;
    cin >> a;
    int n = a.length();
    cout << stringToInt(a, n);
    return 0;
}