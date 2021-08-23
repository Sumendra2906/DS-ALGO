#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char c[1000], ls[1000];
    int n, max = 0;
    cin >> n;
    cin.get();
    while (n > 0)
    {
        n--;
        cin.getline(c, 1000);
        int m = strlen(c);
        if (m > max)
        {
            max = m;
            strcpy(ls, c);
        }
    }
    cout << ls << " " << max << endl;
}