#include <iostream>
using namespace std;

void replace_pi(char *a, int i)
{
    //base case
    if (a[i] == '\0' or a[i + 1] == '\0')
    {
        return;
    }
    //recursive case
    if (a[i] == 'p' and a[i + 1] == 'i')
    {
        int j = i + 2;
        //take j to the end
        while (a[j] != '\0')
        {
            j++;
        }
        while (j >= i + 2)
        {
            a[j + 2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        replace_pi(a, i + 4);
    }
    else
    {
        //go to next position
        replace_pi(a, i + 1);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char s[1005];
        cin >> s;
        replace_pi(s, 0);
        cout << s << endl;
    }
}