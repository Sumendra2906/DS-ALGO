#include <iostream>
using namespace std;

void filter(int n, char s[])
{
    int j = 0;
    while (n)
    {
        int last = n & 1;
        if (last)
        {
            cout << s[j];
        }
        j++;
        n = n >> 1;
    }
    cout << endl;
}

void subsequence(int n, char s[])
{
    for (int i = 0; i < (1 << n); i++)
    {
        filter(i, s);
    }
}

int main()
{
    int n;
    cin >> n;
    char s[100];
    cin >> s;
    subsequence(n, s);
    return 0;
}