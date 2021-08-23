#include <iostream>
using namespace std;

int coin(int *arr, int n)
{
    //base case
    if (n == 0)
    {
        return 0;
    }
    int p;
    //recursive case
    //piyush can take first
    p=arr[0];
    //then the nimit takes first or last
    
}

int main()
{
    int n;
    int arr[30];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << coin(arr, n);
}