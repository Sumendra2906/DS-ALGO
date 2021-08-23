#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int i = 0;
    int n = s.length() + s.length() / 2;
    while (i < n)
    {
        s.insert(i + 1, to_string(s.at(i + 1) - s.at(i)));
        i += 2;
    }
    cout << s;
    return 0;
}