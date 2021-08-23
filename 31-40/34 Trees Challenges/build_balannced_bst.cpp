#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTreefromArray(int arr[], int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    node *root = new node(arr[mid]);
    root->left = buildTreefromArray(arr, s, mid - 1);
    root->right = buildTreefromArray(arr, mid + 1, e);
    return root;
}

void preorderPrint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main()
{
    int t, n;
    int arr[1000];
    cin >> t;
    node *root;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        root = buildTreefromArray(arr, 0, n - 1);
        preorderPrint(root);
        cout << endl;
    }
}