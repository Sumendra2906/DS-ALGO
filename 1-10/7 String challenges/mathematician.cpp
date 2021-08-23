#include <iostream>
#include <cstring>
using namespace std;

void mathematics(char s1[], char s2[])
{
    char ans[105];
    int n = strlen(s1);
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            ans[i] = '1';
        }
        else
        {
            ans[i] = '0';
        }
    }
    ans[n] = '\0';
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        char s1[105];
        char s2[105];
        cin >> s1;
        cin >> s2;
        mathematics(s1, s2);
    }
    return 0;
}