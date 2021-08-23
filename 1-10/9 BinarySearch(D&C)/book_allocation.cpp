#include <iostream>
#include <climits>
using namespace std;

bool can_read(int arr[], int n, int m, int max_pages)
{
    int studentUsed = 1;
    int pagesRead = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesRead + arr[i] > max_pages)
        {
            studentUsed += 1;
            pagesRead = arr[i];
            if (studentUsed > m)
            {
                return false;
            }
        }
        else
        {
            pagesRead += arr[i];
        }
    }
    return true;
}

int book_alot(int arr[], int n, int m)
{
    int ans = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int s = arr[n - 1];
    int e = sum;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (can_read(arr, n, m, mid))
        {
            //then try to decrease the max pages
            ans = min(ans, mid);
            e = mid - 1;
        }
        else
        {
            //not possible to read so  increase the number of pages
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        t--;
        int n, m, arr[1000];
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << book_alot(arr, n, m) << endl;
    }
    return 0;
}