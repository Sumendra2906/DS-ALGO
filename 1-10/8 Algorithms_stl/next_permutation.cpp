#include <iostream>
#include <algorithm>

using namespace std;

int bsearch(int arr[],int l,int r,int key){
    int mid = (l+r)/2;
    int ans = -1;
    while(l<=r){
        if(arr[mid]<key){
            l=mid+1;
        }
        else{
            
        }
    }
}

void perm(int n,int *ar){
        
}

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int n;
        cin >> n;
        int *ar = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }


        for (int i = 0; i < n; i++)
        {
            cout << ar[i] << " ";
        }
        cout << endl;
        delete[] ar;
    }
}