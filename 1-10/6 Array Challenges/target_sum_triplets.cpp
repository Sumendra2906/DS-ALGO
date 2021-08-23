#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int target;
	cin >> target;
	sort(arr, arr + n);
	for (int i = 0; i < n - 2; i++)
	{
		int l = i + 1;
		int r = n - 1;
		while (l < r)
		{
			if (arr[i] + arr[l] + arr[r] < target)
			{
				l++;
			}
			else if ((arr[i] + arr[l] + arr[r]) == target)
			{
				cout << arr[i] << ", " << arr[l] << " and " << arr[r] << endl;
				l++;
				r--;
			}
			else
			{
				r--;
			}
		}
	}
	return 0;
}