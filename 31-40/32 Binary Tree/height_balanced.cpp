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

pair<int, bool> heightBalance(node *root)
{
    pair<int, bool> p;
    if (root == NULL)
    {
        p.first = 0;
        p.second = true;
        return p;
    }
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
    //input 8 10 1 -1 -1 6 9 -1 -1  7 -1 -1 3 -1 14 13 -1 -1 -1
    node *root = buildTree();
    if (heightBalance(root).second)
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }

    return 0;
}