#include <iostream>
using namespace std;

void duplicate(string &s, int i)
{
    //base case
    if (s[i] == '\0' or s[i + 1] == '\0')
    {
        return;
    }
    if (s[i] == s[i + 1])
    {
        //shift and insert *
        s.insert(i+1, "*");
        return duplicate(s, i + 2);
    }
    return duplicate(s, i + 1);
}

int main()
{
    string s;
    cin >> s;
    duplicate(s, 0);
    cout << s;
    return 0;
}