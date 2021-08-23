#include <iostream>
using namespace std;

int main()
{
    int key, n,i;
    int arr[1000];
    cin >> n;
    cout << "Enter the numbers in the array: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the number to find" << endl;
    cin >> key;

    for (i = 0; i < n; i++)
    {
        if(arr[i]==key){
            cout << i << endl;
            break;
        }
    }
    if(i==n){
        cout <<"Element not found" << endl;
    }
}