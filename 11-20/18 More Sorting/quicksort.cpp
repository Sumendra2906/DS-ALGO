#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    //first the smalller  region has 0 elements
    int i = s - 1;
    int pivot = arr[e];
    for (int j = s; j <= e - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            //expand the smaller array and add this smaller element
            i++;
            swap(arr[i], arr[j]);
        }
        //expand the larger region
    }
    //place pivot at correct place
    swap(arr[i + 1], arr[e]);
    return i + 1;
}

void quicksort(int *arr, int s, int e)
{
    //base case
    if (s >= e)
    {
        return;
    }
    //get the index of the pivot element after partition
    int p = partition(arr, s, e);
    //left part
    quicksort(arr, s, p - 1);
    //right part
    quicksort(arr, p + 1, e);
}

int main()
{
    int n;
    cin>>n;
    int arr[200005];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}