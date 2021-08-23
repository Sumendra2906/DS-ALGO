#include <iostream>
using namespace std;

void move(int n, char src, char help, char dest)
{
    //base case
    if (n == 0)
        return;
    //recursive case
    //move n-1 disks from src to the helper
    move(n - 1, src, dest, help);
    //shift nth disk from src  to dest
    cout << "Shift disk " << n << " from " << src << " to " << dest << endl;
    //now we are left with n-1 disks in helper and we have to shift them  to dest
    move(n - 1, help, src, dest);
    return;
}

int main()
{
    int n;
    cin >> n;
    move(n, 'A', 'B', 'C');
    return 0;
}