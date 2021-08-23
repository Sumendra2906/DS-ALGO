#include <iostream>
#include <cstring>
using namespace std;

void remove_duplicate(char c[])
{
    int l = strlen(c);
    if (l == 0 or l == 1)
    {
        return;
    }
    int i = 0;
    for (int j = 1; j < l; j++)
    {
        if (c[i] != c[j])
        {
            i++;
            c[i] = c[j];
        }
    }
    c[i + 1] = '\0';
    return;
}

int main()
{
    char c[1000];
    cin.getline(c, 1000);
    remove_duplicate(c);
    cout << c << endl;
}