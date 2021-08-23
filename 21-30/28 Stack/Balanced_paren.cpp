#include <iostream>
#include <stack>
using namespace std;

bool isValidExp(char *exp)
{
    stack<char> s;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            //stack should not be empty and top should be '('
            if (s.empty() or s.top() != '(')
            {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main()
{
    char s[] = "((a+b)+(c-d+f))";
    cout << isValidExp(s);
    return 0;
}