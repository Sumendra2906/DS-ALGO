#include <iostream>
#include <string>
using namespace std;

string table[] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

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
    string code = table[digit];
    for (int k = 0; k < code.length(); k++)
    {
        output[j] = code[k];
        names(input, output, i + 1, j + 1);
    }
    return;
}

int main()
{
    char input[15];
    char output[15];
    cin >> input;
    names(input, output, 0, 0);
    return 0;
}