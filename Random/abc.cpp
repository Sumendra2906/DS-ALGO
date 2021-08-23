#include <iostream>
using namespace std;
const int MAX_CHAR = 256;


void mergeSort(ll *arr, int s, int e)
{
    //base case
    if (s >= e)
    {
        //if there are 0 or 1 elements then there is no  need to mergeSort
        return;
    }
    int mid = (s + e) / 2;
    //divide
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    //merge
    merge(arr, s, e);
}

void merge(ll *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    ll temp[200005];
    while (i <= mid and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    //now  copy from  temporary array to old array
    for (int i = 0; i <= e; i++)
    {
        arr[i] = temp[i];
    }
}
 
// Returns index of k'th non-repeating character in
// given string str[]
int kthNonRepeating(string str, int k)
{
    int n = str.length();
 
    // count[x] is going to store count of
    // character 'x' in str. If x is not present,
    // then it is going to store 0.
    int count[MAX_CHAR];
 
    // index[x] is going to store index of character
    // 'x' in str.  If x is not  present or x is
    // repeating, then it is going to store  a value
    // (for example, length of string) that cannot be
    // a valid index in str[]
    int index[MAX_CHAR];
 
    // Initialize counts of all characters and indexes
    // of non-repeating  characters.
    for (int i = 0; i < MAX_CHAR; i++)
    {
        count[i] = 0;
        index[i] = n;  // A value more than any index
                       // in str[]
    }
 
    // Traverse the input string
    for (int i = 0; i < n; i++)
    {
        // Find current character and increment its
        // count
        char x = str[i];
        ++count[x];
 
        // If this is first occurrence, then set value
        // in index as index of it.
        if (count[x] == 1)
            index[x] = i;
 
        // If character repeats, then remove it from
        // index[]
        if (count[x] == 2)
            index[x] = n;
    }
 
    // Sort index[] in increasing order.  This step
    // takes O(1) time as size of index is 256 only
    mergeSort(index, 0,MAX_CHAR);
 
    // After sorting, if index[k-1] is value, then
    // return it, else return -1.
    return (index[k-1] != n)? index[k-1] : -1;
}
 
// Driver code
int main()
{
   string str = "geeksforgeeks";
   int k = 3;
   int res = kthNonRepeating(str, k);
   (res == -1)? cout << "There are less than k non-"
                        "repeating characters"
              : cout << "k'th non-repeating character"
                       " is  "<< str[res];
   return 0;
}