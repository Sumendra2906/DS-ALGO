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

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *f = q.front();
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

void print_kth_level(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    //call on it's children
    print_kth_level(root->left, k - 1);
    print_kth_level(root->right, k - 1);
    return;
}
int printAtDistancek(node *root, node *target, int k)
{
    //base case
    //target node is not found
    if (root == NULL)
    {
        return -1;
    }
    //if we reach the target node
    if (root == target)
    {
        print_kth_level(root, k);
        return 0;
    }
    //now ancestor
    int DL = printAtDistancek(root->left, target, k);
    if (DL != -1)
    {
        //node found in left subtree
        if (DL + 1 = k)
        {
            cout << root->data << " ";
        }
        else
        {
            print_kth_level(root->right, k - DL - 2);
        }
        return DL+1;
    }
    int DR = printAtDistancek(root->right, target, k);
    if (DR != -1)
    {
        //node found in left subtree
        if (DL + 1 = k)
        {
            cout << root->data << " ";
        }
        else
        {
            print_kth_level(root->left, k - DR - 2);
        }
        return DR+1;
    }
    return -1;    
}

int main()
{
    //input 8 10 1 -1 -1 6 9 -1 -1  7 -1 -1 3 -1 14 13 -1 -1 -1
    node *root = buildTree();
    bfs2(root);
    return 0;
}