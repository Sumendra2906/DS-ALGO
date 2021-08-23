#include <iostream>
using namespace std;

void permute(char *s, int i)
{
    //base case
    if (s[i] == '\0')
    {
        //print
        cout << s << " ";
        return;
    }
    //recursive case
    for (int j = i; s[j] != '\0'; j++)
    {
        swap(s[i], s[j]);
        permute(s, i + 1);
        //backtracking to restore the original array
        swap(s[i], s[j]);
    }
}

int main()
{
    char s[100];
    cin >> s;
    permute(s, 0);
    return 0;
}