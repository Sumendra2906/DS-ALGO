#include <iostream>
#include <cstring>
using namespace std;

//find the length of the longest substring with non-repeating characters

int main()
{
    char a[] = "abcdefcghijkzyxz";

    int n = strlen(a);
    int current_len = 1;
    int max_len = 1;
    int visited[256];

    for (int i = 0; i < 256; i++)
    {
        visited[i] = -1;
    }
    visited[a[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        int last_occ = visited[a[i]];
        //expansion
        if (last_occ == -1 or i - current_len > last_occ)
        {
            current_len++;
            max_len = max(current_len, max_len);
        }
        //expansion + contraction
        else
        {
            max_len = max(current_len, max_len);
            current_len = i - last_occ;
        }
        visited[a[i]] = i;
    }
    max_len = max(current_len, max_len);
    cout << max_len;
    return 0;
}