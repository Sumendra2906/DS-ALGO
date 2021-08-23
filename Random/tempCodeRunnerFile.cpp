#include<iostream>
using namespace std;

int minJumps(int arr[], int n){
        // Your code here
        int jumps=0;
        int i=0;
        while(i<(n-1)){
            if(arr[i]==0){
                return -1;
            }
            i=i+arr[i];
            jumps++;
    }
    return jumps;
}

int main(){
    int n;
    cin >> n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    cout << minJumps(arr,n);
    return 0;
}