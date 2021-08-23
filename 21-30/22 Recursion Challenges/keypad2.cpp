#include <iostream>
using namespace std;

char keypad[][10] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

void names(char *input, char *output, int i, int j, int &cnt)
{
    //base case
    if (input[i] == '\0')
    {
        cnt++;
        output[j] = '\0';
        cout << output << " ";
        return;
    }
    //recursive case
    int digit = input[i] - '0';
    //we need to handle special case where digit =0 or so we need to  skip it and print the rest
    if (digit == 0)
    {
        names(input, output, i + 1, j,cnt);
    }

    for (int k = 0; keypad[digit][k] != '\0'; k++)
    {
        output[j] = keypad[digit][k];
        //fill the remaining
        names(input, output, i + 1, j + 1, cnt);
    }
    return;
}

int main()
{
    char input[100];
    char output[100];
    cin >> input;
    int cnt = 0;
    names(input, output, 0, 0, cnt);
    cout << endl
         << cnt;
    return 0;
}