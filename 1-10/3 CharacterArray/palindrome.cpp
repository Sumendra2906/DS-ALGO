#include <iostream>
#include <cstring>
using namespace std;

bool palindrome(char c[])
{
    int i = 0;
    int j = strlen(c) - 1;
    while (i < j)
    {
        if (c[i] != c[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    char c[1000];
    cin.getline(c, 1000);
    if (palindrome(c))
    {
        cout << "Palindromic String" << endl;
    }
    else
    {
        cout << "Not a Palindromic String" << endl;
    }
}