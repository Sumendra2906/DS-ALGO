#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

string window(string s, string pat)
{
    int sl = s.length();
    int pl = pat.length();
    int min_len = INT_MAX;
    int start_idx = -1;
    if (pl > sl)
    {
        return "None";
    }
    int smap[256] = {0};
    int pmap[256] = {0};
    for (int i = 0; i < pl; i++)
    {
        char ch = pat[i];
        pmap[ch]++;
    }
    //now start finding window
    int cnt = 0;   //this will store the number of characters matched with the pattern
    int start = 0; //leftmost index of window
    for (int i = 0; i < sl; i++)
    {
        char ch = s[i];
        smap[ch]++;
        //maintain the number of matched characters
        if (pmap[ch] != 0 and smap[ch] <= pmap[ch])
        {
            cnt++;
        }
        if (cnt == pl)
        {
            //pattern is matched
            //now we can contract
            char temp = s[start];
            while (pmap[temp] == 0 or smap[temp] > pmap[temp])
            {
                //it is not needed
                smap[temp]--;
                start++;
                temp = s[start];
            }
            int window_len = i - start + 1;
            if (window_len < min_len)
            {
                min_len = window_len;
                start_idx = start;
            }
        }
    }
    if (start_idx == -1)
    {
        return "None";
    }
    string ans = s.substr(start_idx, min_len);
    return ans;
}

int main()
{
    string s = "hellloeaeo world";
    string pat = "eelo";
    cout << window(s,pat);
    return 0;
}