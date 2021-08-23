#include <iostream>
#include <stack>
using namespace std;

//O(N) Complexity
void stackSpan(int prices[], int n, int span[])
{
    stack<int> s; // store only the indices
    s.push(0);
    span[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int currentPrice = prices[i];
        //we need to find the highest element greater than the current price
        while (!s.empty() and prices[s.top()] <= currentPrice)
        {
            //pop unti the topmost price is higher than the current
            s.pop();
        }
        if (!s.empty())
        {
            span[i] = i - s.top();
        }
        else
        {
            span[i] = i + 1;
        }
        s.push(i);
    }
}

int main()
{
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(int);
    int span[1000] = {0};
    stackSpan(prices, n, span);
    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }
    return 0;
}