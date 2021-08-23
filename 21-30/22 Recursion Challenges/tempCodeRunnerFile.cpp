#include <iostream>
using namespace std;

void removeDup(string &s, int i)
{
    if (s[i] == '\0' or s[i + 1] == '\0')
    {
        return;
    }
    if (s[i] == s[i + 1])
    {
        s.erase(i + 1, 1);
        return removeDup(s, i + 1);
    }
    return (s, i + 1);
}

int main()
{
    string s;
    removeDup(s, 0);
    cout << s;
}