#include <iostream>
#include <queue>
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

void bfs2(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();
            //left is not NULL
            if (f->left)
            {
                q.push(f->left);
            }
            //right is not NULL
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
}

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

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    node *root = buildTreefromArray(arr, 0, n - 1);
    bfs2(root);
    return 0;
}