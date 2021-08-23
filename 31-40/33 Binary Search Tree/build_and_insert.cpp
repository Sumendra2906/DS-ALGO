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

//accepts the old root and data ad returns the new node
node *insertinBST(node *root, int d)
{
    if (root == NULL)
    {
        node *root = new node(d);
        return root;
    }
    if (d <= root->data)
    {
        root->left = insertinBST(root->left, d);
    }
    else
    {
        root->right = insertinBST(root->right, d);
    }
    return root;
}

node *buildTree()
{
    int d;
    //read until you get -1
    node *root = NULL;
    cin >> d;
    while (d != -1)
    {
        root = insertinBST(root, d);
        cin >> d;
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

bool search(node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (data == root->data)
    {
        return true;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}

int main()
{
    //input 5 3 7 1 6 8 -1
    node *root = buildTree();
    bfs2(root);
    cout << search(root,10);
    return 0;
}