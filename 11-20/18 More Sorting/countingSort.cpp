#include <iostream>
#include <climits>
using namespace std;

void countingSort(int *arr, int n)
{
    //find largest
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        largest = max(largest, arr[i]);
    }
    //make the frequenct array and initialize to 0
    int *freq = new int[largest + 1]{0};
    //increase the counts
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    //now put the elements back in the original array
    int j = 0;
    for (int i = 0; i <= largest; i++)
    {
        while (freq[i] != 0)
        {
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
}

int main()
{
    int n;
    int arr[5] = {-7,-5,-2,0,1};
    n = sizeof(arr) / sizeof(int);
    countingSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]*arr[i] << " ";
    }
    return 0;
}