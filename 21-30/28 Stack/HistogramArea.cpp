#include <iostream>
#include <stack>
using namespace std;

int max_area(int arr[], int n)
{
    stack<int> s;
    int area;
    int maxx = 0;
    for (int i = 0; i < n+1; i++)
    {
        if (!s.empty())
        {
            while (arr[i] < arr[s.top()])
            {
                int curr = arr[s.top()];
                s.pop();
                if (!s.empty())
                {
                    area = curr * (i - s.top() - 1);
                    maxx = max(area, maxx);
                }
                else
                {
                    area = curr * i;
                    maxx = max(area, maxx);
                }
            }
        }
        s.push(i);
    }
    return maxx;
}

//Find the largest Area under Histogram

int main()
{
    int n;
    cin >> n;
    int arr[1001];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //pseudo index
    arr[n] = 0;
    cout << max_area(arr, n);
    return 0;
}