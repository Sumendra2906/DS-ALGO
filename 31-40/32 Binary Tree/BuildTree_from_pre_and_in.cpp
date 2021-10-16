#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    //constructor
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

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

int main()
{
    int n;
    cin >> n;
    int pre[1001];
    int ino[1001];
    for (int i = 0; i < n; i++)
    {
        cin >> ino[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    node *root = build_tree_from_traversal(ino, pre, 0, n - 1);
    printPostOrder(root);
    return 0;
}