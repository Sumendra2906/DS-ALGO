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
    bool lchild;
    bool rchild;
    node *root = new node(d);
    cin >> lchild;
    if (!lchild)
    {
        root->left = NULL;
    }
    else
    {
        root->left = buildTree();
    }
    cin >> rchild;
    if (!rchild)
    {
        root->right = NULL;
    }
    else
    {
        root->right = buildTree();
    }
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
    node *root = buildTree();
    bfs2(root);
    return 0;
}
