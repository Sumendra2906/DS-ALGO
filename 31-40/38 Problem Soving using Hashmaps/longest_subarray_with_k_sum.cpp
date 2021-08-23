#include <iostream>
#include <unordered_map>
using namespace std;

int longest_subArray(int n, int arr[], int k)
{
    unordered_map<int, int> um;
    //storing the cs and first occurence index in um
    int len = 0;
    int cs = 0;
    for (int i = 0; i < n; i++)
    {
        cs += arr[i];
        //check for k
        if (cs == k)
        {
            len = max(len, i + 1);
        }
        //check if cs-k is in the map
        else if (um.find(cs - k) != um.end())
        {
            len = max(len, i - um[cs - k]);
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
    int n, k;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    cout << longest_subArray(n, arr, k);
    return 0;
}