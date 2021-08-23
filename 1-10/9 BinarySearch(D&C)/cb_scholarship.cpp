#include <iostream>
using namespace std;

bool possible(long long int n, long long int m, long long int x, long long int y, long long int stu)
{
    long long int avail_coupons = m + (n - stu)*y;
    return avail_coupons>=stu*x;
}

long long int max_students(long long int n, long long int m, long long int x, long long int y)
{
    long long int s = 0;
    long long int e = n;
    long long int ans = 0;
    while (s <= e)
    {
        long long int mid = (s + e) / 2;
        if (possible(n, m, x, y, mid))
        {
            ans = mid;
            //try to increase ans
            s = mid + 1;
        }
        else
        {
            //decrease because not possible
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    long long int n, m, x, y;
    cin >> n >> m >> x >> y;
    cout << max_students(n, m, x, y);
    return 0;
}