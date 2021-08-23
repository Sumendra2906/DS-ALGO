#include <iostream>
#include <algorithm>
using namespace std;

void rotate(int ar[][100], int n)
{
    for (int row = 0; row < n; row++)
    {
        int sc = 0;
        int ec = n - 1;
        while (sc < ec)
        {
            swap(ar[row][sc], ar[row][ec]);
            sc++;
            ec--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(ar[i][j], ar[j][i]);
            }
        }
    }
}

void rotate_stl(int ar[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        reverse(ar[i], ar[i] + n);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(ar[i][j], ar[j][i]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of rows and columns" << endl;
    cin >> n;
    int ar[100][100] = {0};
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
        }
    }
    //rotate(ar, n);
    rotate_stl(ar,n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}
