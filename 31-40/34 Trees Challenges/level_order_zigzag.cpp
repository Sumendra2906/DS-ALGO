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

node *buildTree()
{
    int d;
    bool ex;
    cin >> d;
    cin >> ex;
    if (d==-1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return (max(ls, rs) + 1);
}

void print_kth_level_lr(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    //call on it's children
    print_kth_level_lr(root->left, k - 1);
    print_kth_level_lr(root->right, k - 1);
    return;
}

void print_kth_level_rl(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    //call on it's children
    print_kth_level_rl(root->right, k - 1);
    print_kth_level_rl(root->left, k - 1);
    return;
}

int main()
{
    node *root = buildTree();
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        if (i % 2 == 0)
        {
            print_kth_level_rl(root, i);
        }
        else
        {
            print_kth_level_lr(root, i);
        }
    }
    return 0;
}