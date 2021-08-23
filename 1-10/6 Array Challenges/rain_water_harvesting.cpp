#include <iostream>
#include <algorithm>
using namespace std;

int max_water(int *arr, int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        //max height on the left
        int left = arr[i];
        for (int j = 0; j < i; j++)
        {
            left = max(left, arr[j]);
        }
        //max height on right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            right = max(right, arr[j]);
        }
        res += min(left, right) - arr[i];
    }
    return res;
}

int max_water_eff(int *arr, int n)
{
    int left[n];
    int right[n];

    int water = 0;

    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];

    return water;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int water = max_water_eff(arr, n);
    cout << water;
    delete[] arr;
    return 0;
}