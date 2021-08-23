#include <iostream>
#include <cstring>
using namespace std;

void subsets(char *input, char *output, int i, int j)
{
    //base case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << " ";
        return;
    }
    //recursive case
    //exclude current character
    subsets(input, output, i + 1, j);
    //include current charcater
    output[j] = input[i];
    subsets(input, output, i + 1, j + 1);
}

int main()
{
    char input[1000];
    cin >> input;
    char output[1005];
    int n = strlen(input);
    n = 1 << n;
    subsets(input, output, 0, 0);
    cout << endl
         << n;
    return 0;
}