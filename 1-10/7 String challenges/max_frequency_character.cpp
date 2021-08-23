#include <iostream>
#include <string>
using namespace std;

char max_frequency(string s)
{
    int n = s.length();
    char ans;
    int max = -1;
    int freq[26] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (max < freq[i])
        {
            max = freq[i];
            ans = (char)(i + 'a');
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << max_frequency(s);
    return 0;
}