#include <iostream>
#include <queue>
#include <string>
using namespace std;

//we want to make a priority queue of persons

class Person
{
public:
    string name;
    int age;
    //constructor
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
};

class PersonCompare
{
public:
    bool operator()(Person a, Person b)
    {
        //for getting high to low
        return a.age < b.age;
    }
};

int main()
{
    int n;
    cin >> n;
    //make priority queue
    //at the third position we have to pass in the custom comparator class "not a function"
    priority_queue<Person, vector<Person>, PersonCompare> pq;
    for (int i = 0; i < n; i++)
    {
        string s;
        int age;
        cin >> s;
        cin >> age;
        Person p(s, age);
        pq.push(p);
    }

    int k = 3;
    for (int i = 0; i < k; i++)
    {
        Person p = pq.top();
        cout << p.name << " " << p.age << endl;
        pq.pop();
    }
    return 0;
}