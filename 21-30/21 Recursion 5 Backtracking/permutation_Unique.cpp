#include <iostream>
#include <set>
#include <string>
using namespace std;

void permute(char *s, int i, set<string> &str)
{
    //base case
    if (s[i] == '\0')
    {
        //print
        string t(s);
        str.insert(t);
        //cout << s << " ";
        return;
    }
    //recursive case
    for (int j = i; s[j] != '\0'; j++)
    {
        swap(s[i], s[j]);
        permute(s, i + 1, str);
        //backtracking to restore the original array
        swap(s[i], s[j]);
    }
}

int main()
{
    char s[100];
    cin >> s;
    set<string> str;
    permute(s, 0, str);
    for (auto it : str)
    {
        cout << it << " ";
    }
    return 0;
}