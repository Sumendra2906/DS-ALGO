//print spellings from number
#include <iostream>
using namespace std;

char num[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printSpell(int n)
{
    //base case
    if (n == 0)
    {
        return;
    }
    printSpell(n / 10);
    int digit = n % 10;
    cout << num[digit] << " ";
    return;
}

int main()
{
    int n;
    cin >> n;
    printSpell(n);
    return 0;
}