#include <iostream>
using namespace std;

int merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int cnt = 0;
    int temp[1000];
    while (i <= mid and j <= e)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            //main case for calculating cross inversions
            temp[k++] = arr[j++];
            cnt += (mid - i + 1); //it comes from mid-(i-1)
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= e)
    {
        temp[k++] = arr[j++];
    }
    //copy temp to original
    for (int i = 0; i <= e; i++)
    {
        arr[i] = temp[i];
    }
    return cnt;
}

int count_inversion(int *arr, int s, int e)
{
    //base case
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    int x = count_inversion(arr, s, mid);     //inversions in first array
    int y = count_inversion(arr, mid + 1, e); //inversions in second array
    int z = merge(arr, s, e);                 //cross inversions
    return x + y + z;
}

int main()
{
    int arr[] = {1, 5, 2, 6, 3, 0};
    int n = sizeof(arr) / sizeof(int);
    cout << count_inversion(arr, 0, n - 1);
    return 0;
}