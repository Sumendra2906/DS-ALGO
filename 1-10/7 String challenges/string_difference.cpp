#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int i = 0;
    string a;
    while (i < s.length()-1)
    {
        a = to_string(s.at(i + 1) - s.at(i));
        s.insert(i + 1, a);
        i+=a.length()+1;
    }
    cout << s;
    return 0;
}