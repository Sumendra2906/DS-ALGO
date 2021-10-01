#include <iostream>
#include <algorithm>
using namespace std;

int coin_change(int coins[], int size, int money)
{
    int ans = 0;
    while (money > 0)
    {
        //upper bound will give the adress of the next value greater than money
        int idx = upper_bound(coins, coins + size, money) - 1 - coins;
        money = money - coins[idx];
        ans++;
    }
    return ans;
}

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int size = sizeof(coins) / sizeof(int);
    int money;
    cin >> money;
    cout << coin_change(coins, size, money);
    return 0;
}