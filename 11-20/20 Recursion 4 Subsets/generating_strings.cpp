#include <iostream>
using namespace std;

char dict[28] = {'\0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};

void generate(char *in, char *out, int i, int j)
{
    //base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    //special case abot 0
    int digit = in[i] - '0';
    //take a single number
    //char ch = digit + 'A' - 1; // digit is 1 then it becomes 1+A-1 so A
    out[j] = dict[digit];
    generate(in, out, i + 1, j + 1);
    //taking both
    if (in[i + 1] != '\0')
    {
        int second = in[i + 1] - '0';
        int num = digit * 10 + second;
        if (num <= 26)
        {
            //ch = num - 'A' - 1;
            out[j] = dict[num];
            generate(in, out, i + 2, j + 1);
        }
    }
    return;
}

int main()
{
    char in[1000];
    cin >> in;
    char out[1001];
    generate(in, out, 0, 0);
    return 0;
}