#include <iostream>
#include <vector>
using namespace std;

class Student
{
public:
    int marks;
    string name;
};
//accepting array of students
void bucketSort(Student s[], int n)
{
    //when marks are in the range 0-100
    //array of vectors where each element of this array is a vector
    vector<Student> v[101];

    for (int i = 0; i < n; i++)
    {
        int marks = s[i].marks;
        v[marks].push_back(s[i]);
    }
    //interate of the vector and print the students
    for (int i = 100; i >= 0; i--)
    {
        for (auto it = v[i].begin(); it != v[i].end(); it++)
        {
            cout << (*it).marks << " "<<(*it).name << endl;
        }
    }
}

int main()
{
    Student s[10000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].marks >> s[i].name;
    }
    bucketSort(s, n);
    return 0;
}