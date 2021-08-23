#include <iostream>
#include <queue>
#include <algorithm>
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

//accepts the old root and data ad returns the new node
node *insertinBST(node *root, int d)
{
    if (root == NULL)
    {
        node *root = new node(d);
        return root;
    }
    if (d <= root->data)
    {
        root->left = insertinBST(root->left, d);
    }
    else
    {
        root->right = insertinBST(root->right, d);
    }
    return root;
}

node *buildTree()
{
    int d;
    //read until you get -1
    node *root = NULL;
    cin >> d;
    while (d != -1)
    {
        root = insertinBST(root, d);
        cin >> d;
    }
    return root;
}

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

node *build_tree_from_traversal(int *ino, int *pre, int s, int e)
{
    //base case
    if (s > e)
    {
        return NULL;
    }
    //static pointer to the preorder array
    static int i = 0;
    //make node
    node *root = new node(pre[i]);
    //search for it's index in the inorder array
    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (pre[i] == ino[j])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = build_tree_from_traversal(ino, pre, s, index - 1);
    root->right = build_tree_from_traversal(ino, pre, index + 1, e);
    return root;
}

int main()
{
    //input 5 3 7 1 6 8 -1
    int pre[999], in[999];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
        in[i] = pre[i];
    }
    sort(in, in + n);
    node* root = build_tree_from_traversal(in, pre, 0, n - 1);
    bfs2(root);
    return 0;
}