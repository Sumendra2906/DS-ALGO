#include <iostream>
#include <cstring>
using namespace std;

bool palindrome(char ch[])
{
    int i = 0;
    int j = strlen(ch) - 1;
    while (i < j)
    {
        if (ch[i] == ch[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool palrecursion(char ch[], int left, int right)
{
    //BaseCase
    if (strlen(ch) == 0 || strlen(ch) == 1)
    {
        return true;
    }
    if (ch[left] == ch[right])
    {
        
        palrecursion(ch, left + 1, right - 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    char ch[n + 1];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ch[i];
    }
    ch[n] = '\0';
    if (palrecursion(ch, 0, strlen(ch)))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}