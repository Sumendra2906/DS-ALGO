#include <iostream>
#include <vector>
using namespace std;

//different style of writing the same function
//for loop to recursion

void linearSearch(int *arr, int i, int n, int key, vector<int> &ans)
{
    //base case
    if (i == n)
    {
        return;
    }
    if (arr[i] == key)
    {
        ans.push_back(i);
    }
    linearSearch(arr, i + 1, n, key, ans);
}
int main()
{
    int n, key;
    vector<int> ans;
    cin >> n;
    int arr[100005];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> key;
    linearSearch(arr, 0, n, key, ans);
    for (auto it:ans)
    {
        cout << it << " ";
    }
    return 0;
}