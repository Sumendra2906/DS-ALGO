#include <iostream>
using namespace std;

int max_sum_sub(int **arr, int n, int m)
{
    //ColumWise
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            arr[i][j] += arr[i][j + 1];
        }
    }
    //RowWise
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            arr[i][j] += arr[i+1][j];
        }
    }
    int result = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result = max(result, arr[i][j]);
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << max_sum_sub(arr, n, m) << endl;
    return 0;
}