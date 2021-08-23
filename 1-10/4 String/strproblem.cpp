#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//Extract Token
string extract(string str, int key)
{
    char *s = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

int convertToInt(string str)
{
    int ans = 0;
    int p = 1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        ans += ((str[i] - '0') * p);
        p = p * 10;
    }
    return ans;
}

bool numericComp(pair<string, string> s1, pair<string, string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return convertToInt(key1) < convertToInt(key2);
}

bool lexComp(pair<string, string> s1, pair<string, string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return key1 < key2;
}

int main()
{
    int n;
    cin >> n;
    cin.get();
    string a[100];
    for (int i = 0; i < n; i++)
    {
        getline(cin, a[i]);
    }
    int key;
    string reverse, order;
    cin >> key >> reverse >> order;

    pair<string, string> strPair[100];
    for (int i = 0; i < n; i++)
    {
        strPair[i].first = a[i];
        strPair[i].second = extract(a[i], key);
    }

    if (order == "numeric")
    {
        sort(strPair, strPair + n, numericComp);
    }
    else
    {
        sort(strPair, strPair + n, lexComp);
    }
    if (reverse == "true")
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(strPair[i], strPair[n - i - 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << strPair[i].first << endl;
    }

    return 0;
}