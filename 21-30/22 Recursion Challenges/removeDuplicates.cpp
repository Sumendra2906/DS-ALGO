#include <iostream>
#include <string>
using namespace std;

void removeDup(string &s, int i)
{
    if (s[i] == '\0' or s[i + 1] == '\0')
    {
        return;
    }
    if (s[i] == s[i + 1])
    {   //remove the ith element so  the i +1 th becomes ith element.
        s.erase(i, 1);
        return removeDup(s, i);
    }
    return removeDup(s, i + 1);
}

int main()
{
    string s;
    cin >> s;
    removeDup(s, 0);
    cout << s;
}