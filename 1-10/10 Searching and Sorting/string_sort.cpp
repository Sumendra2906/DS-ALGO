#include <iostream>
using namespace std;

bool subst(string a, string b)
{
    int counter = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (counter == b.length())
        {
            return true;
        }
        if (a[i] == b[counter])
        {
            counter++;
        }
        else
        {
            counter = 0;
        }
    }
    return false;
}

bool compare(string a, string b)
{
    if (subst(a, b) or subst(b, a))
    {
        return a.length()>b.length();
    }
    return (a < b);
}

void string_sort(int n, string *ar,bool (&compare)(string a,string b))
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(ar[j+1],ar[j]))
            {
                swap(ar[j], ar[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string *ar = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    string_sort(n, ar,compare);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << endl;
    }
    delete[] ar;
    return 0;
}