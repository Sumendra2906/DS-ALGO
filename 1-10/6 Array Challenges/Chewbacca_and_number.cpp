#include <iostream>
#include <string>
using namespace std;

int main()
{
    char ar[20];
    cin >> ar;
    int i = 1;
    if (ar[0] > '4' && ar[0] != '9')
    {
        ar[0] = 48 + '9' - ar[0];
    }
    while (ar[i] != '\0')
    {
        if (ar[i] > '4')
        {
            ar[i] = 48 + '9' - ar[i];
        }
        i++;
    }
    cout << ar;
    return 0;
}