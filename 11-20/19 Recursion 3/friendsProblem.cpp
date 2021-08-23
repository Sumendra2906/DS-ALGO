//there are n  friends. In how many ways can they go to a aparty if they want to go solo or alone.
#include <iostream>
using namespace std;

int party(int n)
{
    //base case
    if (n == 0 or n == 1)
    {
        return 1;
        //if 0 then don't go anywhere and if 1 then go alone so 1 way each.
    }
    return party(n - 1) + (n - 1) * party(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << party(n) << endl;
    return 0;
}