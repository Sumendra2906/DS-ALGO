#include <iostream>
using namespace std;

int binaryString(int n)
{
    //base case
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 2;
    }
    //recursive case
    return binaryString(n - 1) + binaryString(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << binaryString(n) << endl;
    return 0;
}