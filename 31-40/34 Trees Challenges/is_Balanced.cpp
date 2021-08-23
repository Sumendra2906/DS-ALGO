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
    bool ex;
    cin >> d;
    cin >> ex;
    if (!ex)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

pair<int, bool> heightBalance(node *root)
{
    pair<int, bool> p;
    if (root == NULL)
    {
        p.first = 0;
        p.second = true;
        return p;
    }
    //bottom up traversal
    pair<int, bool> left = heightBalance(root->left);
    pair<int, bool> right = heightBalance(root->right);
    //for current
    p.first = max(left.first, right.first) + 1;
    if (abs(left.first - right.first) <= 1 and left.second and right.second)
    {
        p.second = true;
    }
    else
    {
        p.second = false;
    }
    return p;
}

int main()
{
    node *root = buildTree();
    if (heightBalance(root).second)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}