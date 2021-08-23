#include <iostream>
#include <vector>
using namespace std;

void print_factors(int n)
{
    int cnt;
    vector<pair<int, int>> fact;
    for (int i = 2; i * i <= n; i++)
    {
        cnt = 0;
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            fact.push_back(make_pair(i, cnt));
        }
    }
    if (n != 1)
    {
        fact.push_back(make_pair(n, 1));
    }
    for (auto p : fact)
    {
        cout << p.first << '^' << p.second << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    print_factors(n);
    return 0;
}