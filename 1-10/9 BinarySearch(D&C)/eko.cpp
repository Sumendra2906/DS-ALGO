#include <iostream>
using namespace std;

bool possible(int n, int m, int *ar,int height){
    int tot_wood=0;
    for(int i=0;i<n;i++){
        if(ar[i]>height){
            tot_wood+=(ar[i]-height);
            if(tot_wood>=m){
                return true;
            }
        }
    }
    return false;
}

int cut(int n, int m, int *ar)
{
    int s = 0;
    int imax = 0;
    for (int i = 0; i < n; i++)
    {
        imax = max(imax, ar[i]);
    }
    int e = imax;
    int ans;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (possible(n,m,ar,mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << cut(n, m, ar);
    delete[] ar;
    return 0;
}