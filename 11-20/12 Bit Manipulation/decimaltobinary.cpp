#include <iostream>
using namespace std;

int dectobin(int n)
{
    int ans;
    //make the output a base 10 integer otherwise it will be reversed if we will print directly
    int p = 1;
    while (n)
    {
        int last = n & 1;
        ans += last * p;
        p = p * 10;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << dectobin(n) << endl;
    return 0;
}