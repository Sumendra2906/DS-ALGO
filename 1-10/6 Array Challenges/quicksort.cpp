#include <iostream>
using namespace std;

int partition(int ar[], int low, int high);

void quicksort(int ar[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(ar, low, high);
        quicksort(ar, low, pi - 1);
        quicksort(ar, pi + 1, high);
    }
}

int partition(int ar[], int low, int high)
{
    int pivot = ar[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (ar[j] < pivot)
        {
            i++;
            swap(ar[i], ar[j]);
        }
    }
    swap(ar[i + 1], ar[high]);
    return i + 1;
}

int main()
{
    int *ar = new int[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> ar[i];
    }
    quicksort(ar, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << ar[i]<<" ";
    }
    return 0;
}