#include <iostream>
using namespace std;

int tile(int n)
{
    //base case
    if (n <= 3)
        return 1;
    //recursive case
    return tile(n - 1) +
           tile(n - 4);
}

int main()
{
    int n;
    cin >> n;
    //wall is of size 4*n
    cout << tile(n);
    return 0;
}