#include <iostream>
using namespace std;

int main()
{
    char ch[1001];
    cin >> ch;
    int i, j = 0;
    for (i = 1; ch[i] != '\0'; i++)
    {
        if (ch[i] >= 'A' && ch[i] <= 'Z')
        {
            while (j < i)
            {
                cout << ch[j];
                j++;
            }
            cout << endl;
        }
    }
    while(j<i){
        cout<<ch[j];
        j++;
    }
    return 0;
}