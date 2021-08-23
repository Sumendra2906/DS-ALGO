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

void printPreorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    //print the root node and then it's children
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    //print the left and then root and then right
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPostOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    //print the left and then right and then root
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
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

void print_kth_level(node *root, int k)
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
    print_kth_level(root->left, k - 1);
    print_kth_level(root->right, k - 1);
    return;
}

int main()
{
    node *root = buildTree();
    /*
    printPreorder(root);
    cout << endl;
    printInorder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    */
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        print_kth_level(root, i);
        cout << endl;
    }
    return 0;
}