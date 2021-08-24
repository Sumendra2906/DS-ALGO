#include <iostream>
#include <unordered_map>
using namespace std;

int longest_consequtive_subsequence(int n, int arr[])
{
    unordered_map<int, int> m; //we are storing number,length
    for (int i = 0; i < n; i++)
    {
        int no = arr[i];
        if (m.count(no - 1) == 0 and m.count(no + 1) == 0)
        {
            //start a new streak with length 1
            m[no] = 1;
        }
        else if (m.count(no - 1) and m.count(no + 1))
        {
            int len1 = m[no - 1];
            int len2 = m[no + 1];
            int streak = len1 + 1 + len2;
            //now update this new length at the starting and the ending index
            m[no - len1] = streak;
            m[no + len2] = streak;
        }
        else if (m.count(no - 1) and m.count(no + 1) == 0)
        {
            //left is present
            int len = m[no - 1];
            m[no] = len + 1;
            m[no - len] = len + 1;
        }
        else
        {
            //right is present
            int len = m[no + 1];
            m[no] = len + 1;
            m[no + len] = len + 1;
        }
    }
    int largest = 0;
    for (auto p : m)
    {
        largest = max(largest, p.second);
    }
    return largest;
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