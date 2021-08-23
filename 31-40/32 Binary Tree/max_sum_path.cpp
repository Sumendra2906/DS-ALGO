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

class Pair
{
public:
    int BranchSum;
    int maxSum;

    Pair()
    {
        BranchSum = 0;
        maxSum = 0;
    }
};

Pair maxSumPath(node *root)
{
    Pair p;
    if (root == NULL)
    {
        return p;
    }
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    int op1 = root->data;
    int op2 = root->data + left.BranchSum;
    int op3 = root->data + right.BranchSum;
    int op4 = root->data + left.BranchSum + right.BranchSum;
    //current ans passing through root
    int curr = max(op1, max(op2, max(op3, op4)));
    //branch sum
    p.BranchSum = max(left.BranchSum, max(right.BranchSum, 0)) + root->data;
    p.maxSum = max(curr, max(left.maxSum, right.maxSum));
    return p;
}

int main()
{
    node *root = buildTree();
    cout << maxSumPath(root).BranchSum;
    return 0;
}