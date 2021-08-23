#include <iostream>
#include <cstring>
using namespace std;

void movex(char *in, int i, int n)
{
    //base case
    if (i == n)
    {
        cout << in << endl;
        return;
    }
    if (in[i] == 'x')
    {
        int j = i;
        while (j < n - 2)
        {
            in[j] = in[j + 1];
            j++;
        }
        in[j] = 'x';
        movex(in, i, n - 1);
        return;
    }
    movex(in, i + 1, n);
    return;
}

int main()
{
    char in[1005];
    cin >> in;
    int n = strlen(in);
    movex(in,0,n+1);
    return 0;
}