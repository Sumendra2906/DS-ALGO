#include <iostream>
using namespace std;

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void names(char *input, char *output, int i, int j)
{
    //base case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    //recursive case
    int digit = input[i] - '0';
    //we need to handle special case where digit =0 or so we need to  skip it and print the rest
    if (digit == 0 or digit == 1)
    {
        names(input, output, i + 1, j);
    }

    for (int k = 0; keypad[digit][k] != '\0'; k++)
    {
        output[j] = keypad[digit][k];
        //fill the remaining
        names(input, output, i + 1, j + 1);
    }
    return;
}

int main()
{
    char input[100];
    char output[100];
    cin >> input;
    names(input, output, 0, 0);
    return 0;
}