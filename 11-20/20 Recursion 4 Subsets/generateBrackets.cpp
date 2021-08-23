#include <iostream>
using namespace std;

void generateBrackets(char *bracket, int n, int idx, int open, int close)
{
    //base case
    if (idx == 2 * n)
    {
        bracket[idx + 1] = '\0';
        cout << bracket << endl;
        return;
    }
    //putting close
    if (close < open)
    {
        bracket[idx] = ')';
        generateBrackets(bracket, n, idx + 1, open, close + 1);
    }
    //puting open
    if (open < n)
    {
        bracket[idx] = '(';
        generateBrackets(bracket, n, idx + 1, open + 1, close);
    }
}

int main()
{
    int n;
    cin >> n;
    int idx = 0;
    char bracket[1005];
    generateBrackets(bracket, n, idx, 0, 0);
    return 0;
}