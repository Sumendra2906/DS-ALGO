#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	int target;
	cin >> target;
	int l=0,r=n-1;
	sort(ar,ar+n);
	while(l<r){
		if(ar[l]+ar[r]<target){
			l++;
		}
		else if((ar[l]+ar[r])==target){
			cout<<ar[l]<<" and "<<ar[r]<<endl;
			l++;
			r--;
		}
		else{
			r--;
		}
	}
	return 0;
}