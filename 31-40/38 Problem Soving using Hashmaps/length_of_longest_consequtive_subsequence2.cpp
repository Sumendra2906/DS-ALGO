#include <iostream>
#include <unordered_set>
using namespace std;

int longest_consequtive_subsequence(int n, int arr[])
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]); //O(1)
    }
    //iterate again
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        if (s.find(curr - 1) == s.end())
        {
            //number not found so it can be starting point of streak
            int next = curr + 1;
            int len = 1;
            while (s.find(next) != s.end())
            {
                len++;
                next++;
            }
            count = max(count, len);
        }
    }
    return count;
}


int main()
{
    int n;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << longest_consequtive_subsequence(n, arr);
    return 0;
}