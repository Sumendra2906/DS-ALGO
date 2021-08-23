#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

class Student
{
public:
    string firstname;
    string lastname;
    int roll_no;

    Student(string f, string l, int r)
    {
        firstname = f;
        lastname = l;
        roll_no = r;
    }

    bool operator==(const Student &s) const
    {
        return roll_no == s.roll_no;
    }
};

class HashFn
{
public:
    //unsigned it that returns the size of objects in bytes
    size_t operator()(const Student &s) const
    {
        //calculate the hash value
        return s.firstname.length() + s.lastname.length();
    }
};

int main()
{
    unordered_map<Student, int, HashFn> um;
    Student s1("Sumendra", "Singh", 217);
    Student s2("Parvez", "Alam", 137);
    Student s3("Sahil", "Jain", 825);
    Student s4("Sahil", "Jain", 69);

    um[s1] = 100;
    um[s2] = 60;
    um[s3] = 70;
    um[s4] = 90;

    for (auto s : um)
    {
        cout << s.first.firstname << " " << s.first.lastname << " Marks " << s.second << endl;
    }

    return 0;
}