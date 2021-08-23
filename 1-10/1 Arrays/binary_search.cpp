#include <iostream>
using namespace std;
int binary_search(int ar[], int n, int key);
int main()
{
    int n, ar[1000], key, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << "Enter the element to find: ";
    cin >> key;
    cout << binary_search(ar, n, key);

    return 0;
}

int binary_search(int ar[], int n, int key)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (ar[mid] == key)
        {
            return mid;
        }
        else if (ar[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
