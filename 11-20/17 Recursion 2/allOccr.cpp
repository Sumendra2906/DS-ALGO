#include <iostream>
using namespace std;

void linearSearch(int *arr, int i, int n, int key)
{
    if (i == n)
    {
        return;
    }
    if (arr[i] == key)
    {
        cout << i << " ";
    }
    linearSearch(arr, i + 1, n, key);
}

int storeOcc(int *arr, int i, int n, int key, int *out, int j)
{
    if (i == n)
    {
        return j;
    }
    if (arr[i] == key)
    {
        out[j] = i;
        return storeOcc(arr, i + 1, n, key, out, j + 1);
    }
    return storeOcc(arr, i + 1, n, key, out, j);
}

int main()
{
    int n, key;
    cin >> n;
    int arr[10000];
    int out[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> key;
    linearSearch(arr, 0, n, key);
    cout << endl;
    int j = storeOcc(arr, 0, n, key, out, 0);
    for (int i = 0; i < j; i++)
    {
        cout << out[i] << endl;
    }
    return 0;
}