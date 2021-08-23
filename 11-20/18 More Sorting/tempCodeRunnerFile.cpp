void mergeSort(ll *arr, ll s, ll e)
{
    //base case
    if (s >= e)
    {
        //if there are 0 or 1 elements then there is no  need to sort
        return;
    }
    ll mid = (s + e) / 2;
    //divide
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    //merge
    merge(arr, s, e);
}

int main()
{
    ll n;
    cin >> n;
    ll arr[200005];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}