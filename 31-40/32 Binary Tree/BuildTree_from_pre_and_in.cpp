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

void bfs2(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();
            //left is not NULL
            if (f->left)
            {
                q.push(f->left);
            }
            //right is not NULL
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
}

int main()
{
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int ino[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int n = 8;
    node *root = build_tree_from_traversal(ino, pre, 0, n - 1);
    bfs2(root);
    return 0;
}