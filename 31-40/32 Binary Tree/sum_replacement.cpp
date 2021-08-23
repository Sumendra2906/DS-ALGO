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

int replacement(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }
    int leftSum = replacement(root->left);
    int rightSum = replacement(root->right);
    //current sum
    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp + root->data;
}

int main()
{
    //input 8 10 1 -1 -1 6 9 -1 -1  7 -1 -1 3 -1 14 13 -1 -1 -1
    node *root = buildTree();
    replacement(root);
    printPreorder(root);

    return 0;
}