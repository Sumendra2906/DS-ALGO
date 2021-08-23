#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char c;
    cin >> c;
    if (islower(c))
    {
        cout << 'L';
    }
    else if (isupper(c))
    {
        cout << 'U';
    }
    else
    {
        cout << 'I';
    }
    return 0;
}