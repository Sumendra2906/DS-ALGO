#include <iostream>
#include <queue>
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

void print_pre(node *root)
{
    if(root==NULL){
        return;
    }
    if(root->left==NULL){
        cout << "END"<<" => "
        cout<<root->data<<" ";
        cout<<root->right;
    }
}

int main()
{
    int pre[10000] int ino[10000];
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> ino[m];
    }

    node *root = build_tree_from_traversal(ino, pre, 0, n - 1);
    bfs2(root);
    return 0;
}