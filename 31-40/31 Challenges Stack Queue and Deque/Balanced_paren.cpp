#include <iostream>
#include <stack>
using namespace std;

bool isValidExp(char *exp)
{
    stack<char> s;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' or exp[i] == '{' or exp[i] == '[')
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
        else if (exp[i] == '}')
        {
            //stack should not be empty and top should be '{'
            if (s.empty() or s.top() != '{')
            {
                return false;
            }
            s.pop();
        }
        else if (exp[i] == ']')
        {
            //stack should not be empty and top should be '['
            if (s.empty() or s.top() != '[')
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
    char s[100005];
    cin >> s;
    if (isValidExp(s))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}