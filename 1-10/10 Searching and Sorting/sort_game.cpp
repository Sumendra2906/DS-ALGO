#include <iostream>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

void selection_sort(int n, pair<string, int> *ar, bool (&compare)(pair<string, int> a, pair<string, int> b))
{
    int idx_min;
    for (int i = 0; i < n - 1; i++)
    {
        idx_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (compare(ar[j], ar[idx_min]))
            {
                idx_min = j;
            }
        }
        swap(ar[i], ar[idx_min]);
    }
}

int main()
{
    int n, x;
    cin >> x;
    cin >> n;
    pair<string, int> *ar = new pair<string, int>[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i].first;
        cin >> ar[i].second;
    }
    selection_sort(n, ar, compare);
    for (int i = 0; i < n; i++)
    {
        if (ar[i].second >= x)
        {
            cout << ar[i].first << " ";
            cout << ar[i].second << endl;
        }
    }
    delete[] ar;
    return 0;
}