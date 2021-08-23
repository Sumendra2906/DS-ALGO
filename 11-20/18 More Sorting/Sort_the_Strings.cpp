#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//extract token based on key
string extractToken(string str, int key)
{
    /*we need to convert string to char* for that we need to access
    the underlying array of this string we can do that by
    str.c_str() function and then type casting it to char* */
    char *s = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

int convertToInt(string s)
{
    int ans = 0;
    int p = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        ans += ((s[i] - '0') * p);
        p *= 10;
    }
    return ans;
}

bool lexCompare(pair<string, string> a, pair<string, string> b)
{
    string k1, k2;
    k1 = a.second;
    k2 = b.second;
    return k1 < k2;
}

bool numericCompare(pair<string, string> a, pair<string, string> b)
{
    string k1, k2;
    k1 = a.second;
    k2 = b.second;
    return convertToInt(k1) < convertToInt(k2);
}

int main()
{
    int n;
    cin >> n;
    cin.get(); //to consume the extra '\n'
    string s[1000];
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }

    int key;
    string reversal, order;
    cin >> key >> reversal >> order;
    //make an array of pairs to store strings along with keys
    pair<string, string> str_pair[1000];
    for (int i = 0; i < n; i++)
    {
        str_pair[i].first = s[i];
        str_pair[i].second = extractToken(s[i], key);
    }

    //now sort
    if (order == "numeric")
    {
        sort(str_pair, str_pair + n, numericCompare);
    }
    else
    {
        sort(str_pair, str_pair + n, lexCompare);
    }

    //reversal
    if (reversal == "true")
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(str_pair[i], str_pair[n - i - 1]);
        }
    }

    //print
    for (int i = 0; i < n; i++)
    {
        cout << str_pair[i].first << endl;
    }

    return 0;
}