#include <iostream>
#include "vector.h"
using namespace std;

int main()
{

    Vector<char> v;
    v.push_back('6');
    v.push_back('9');
    v.push_back('2');
    v.push_back('3');
    v.pop_back();
    v.push_back('4');

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}