#include <iostream>
using namespace std;

void readlines(char ar[], int n, char delim = '\n')
{
    int i = 0;
    char ch = cin.get();
    while (ch != delim)
    {
        ar[i] = ch;
        i++;
        if (i == (n - 1))
        {
            break;
        }
        ch = cin.get();
    }
    ar[i] = '\0';
}

int main()
{
    char ar[1000];
    //readlines(ar, 1000,'$');
    cin.getline(ar,1000,'$');
    cout << ar;
}