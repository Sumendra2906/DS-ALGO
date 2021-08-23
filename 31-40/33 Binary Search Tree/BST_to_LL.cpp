#include <iostream>
#include <climits>
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

class LinkedList
{
public:
    node *head;
    node *tail;
};

LinkedList flatten(node *root)
{
    LinkedList l;
    if (root == NULL)
    {
        l.head = l.tail = NULL;
    }
    //0 children -> Leaf Node
    if (root->left == NULL and root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }
    //only left child
    if (root->left != NULL and root->right == NULL)
    {
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    //only right child
    if (root->left == NULL and root->right != NULL)
    {
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    //both children are present
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);
    leftLL.tail->right = root;
    root->right = rightLL.head;
    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

int main()
{
    //input 5 3 7 1 6 8 -1
    node *root = buildTree();
    bfs2(root);
    LinkedList l = flatten(root);
    node *temp = l.head;
    while (temp != NULL)
    {
        cout << temp->data << "--> ";
        temp = temp->right;
    }
    return 0;
}