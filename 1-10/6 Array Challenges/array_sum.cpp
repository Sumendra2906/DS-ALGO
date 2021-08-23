#include <iostream>
using namespace std;

int main()
{
    int n, m, carry = 0;
    cin >> n;
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cin >> m;
    int *arr = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int res[1002];
    int i = 0, sum;
    while (n != 0 && m != 0)
    {
        sum = ar[n - 1] + arr[m - 1] + carry;
        res[i] = sum % 10;
        carry = sum / 10;
        i++;
        n--;
        m--;
    }
    while (m)
    {
        sum = arr[m - 1] + carry;
        res[i] = sum % 10;
        carry = sum / 10;
        i++;
        m--;
    }
    while (n)
    {
        sum = ar[n - 1] + carry;
        res[i] = sum % 10;
        carry = sum / 10;
        i++;
        n--;
    }
    while (carry)
    {
        res[i] = carry % 10;
        carry = carry / 10;
        i++;
    }
    for (i = i - 1; i >= 0; i--)
    {
        cout << res[i] << ", ";
    }
    cout << "END";
    delete[] arr;
    delete[] ar;
    return 0;
}