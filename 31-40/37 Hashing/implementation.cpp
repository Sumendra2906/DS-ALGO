#include <iostream>
#include <cstring>
#include "hashtable.h"
using namespace std;

int main()
{
    HashTable<int> price;
    price.insert("Burger", 120);
    price.insert("Pepsi", 40);
    price.insert("Pizza", 200);
    price.insert("Shake", 100);
    price.insert("Noodles", 150);
    price.insert("Coke", 150);
    price.print();
    price.erase("Burger");
    price.print();
    return 0;
}