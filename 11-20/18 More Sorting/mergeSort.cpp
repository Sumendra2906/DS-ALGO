#include <iostream>
#define ll long long
using namespace std;

void merge(ll *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    ll temp[200005];
    while (i <= mid and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    //now  copy from  temporary array to old array
    for (int i = 0; i <= e; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(ll *arr, int s, int e)
{
    //base case
    if (s >= e)
    {
        //if there are 0 or 1 elements then there is no  need to sort
        return;
    }
    int mid = (s + e) / 2;
    //divide
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    //merge
    merge(arr, s, e);
}

int main()
{
    int n;
    cin >> n;
    ll arr[200005];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}