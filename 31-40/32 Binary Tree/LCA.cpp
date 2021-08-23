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

node *lca(node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == a or root->data == b)
    {
        return root;
    }
    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);

    if (leftans != NULL and rightans != NULL)
    {
        return root;
    }
    if (leftans != NULL)
    {
        return leftans;
    }
    else
    {
        return rightans;
    }
}

node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main()
{
    //input 8 10 1 -1 -1 6 9 -1 -1  7 -1 -1 3 -1 14 13 -1 -1 -1
    node *root = buildTree();
    cout << lca(root, 7, 13)->data;
    return 0;
}