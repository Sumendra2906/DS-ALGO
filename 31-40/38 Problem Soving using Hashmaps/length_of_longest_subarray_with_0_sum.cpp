#include <iostream>
#include <unordered_map>
using namespace std;

int longest_subArray(int n, int arr[])
{
    unordered_map<int, int> um;
    //storing the cs and first occurence index in um
    int len = 0;
    int cs = 0;
    for (int i = 0; i < n; i++)
    {
        cs += arr[i];
        //check for 0
        if (cs == 0)
        {
            len = max(len, i + 1);
        }
        //check if it is already in um
        else if (um.find(cs) != um.end())
        {
            //present
            len = max(len, i - um[cs]);
        }
        else
        {
            um[cs] = i;
        }
    }
    return len;
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
    cout << longest_subArray(n, arr);
    return 0;
}