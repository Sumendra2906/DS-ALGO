#include <iostream>
#include <cstring>

using namespace std;

//static token means the state of this variable will remain the same as in the last call of the function

char *mystrtok(char *str, char delim)
{
    static char *input = NULL;
    if (str != NULL)
    {
        input = str;
    }

    if (input == NULL)
    {
        return NULL;
    }

    char *output = new char[strlen(str) + 1];
    int i = 0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] != delim)
        {
            output[i] = input[i];
        }
        else
        {
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }
    output[i] = '\0';
    input = NULL;
    return output;
}

int main()
{
    char s[100] = "Today is a sunny day";
    char *ptr = mystrtok(s, ' ');
    cout << ptr << endl;

    while (ptr != NULL)
    {
        ptr = mystrtok(NULL, ' ');
        cout << ptr << endl;
    }

    return 0;
}