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

void printRightView(node *root, int level, int &maxlevel)
{
    if (root == NULL)
    {
        return;
    }
    if (level > maxlevel)
    {
        //we have discovered a new level
        cout << root->data << " ";
        maxlevel = level;
    }
    //call on right
    printRightView(root->right, level + 1, maxlevel);
    printRightView(root->left, level + 1, maxlevel);
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
    node *root = buildTree();
    int maxlevel = -1;
    printRightView(root, 0, maxlevel);
    return 0;
}