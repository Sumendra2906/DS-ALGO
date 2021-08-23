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
            //cout << f->data << " ";
            q.pop();
            //left is not NULL
            if (f->left)
            {
                cout << f->left->data << " => ";
                q.push(f->left);
            }
            else
            {
                cout << "End => ";
            }
            cout << f->data << " <= ";
            //right is not NULL
            if (f->right)
            {
                cout << f->right->data;
                q.push(f->right);
            }
            else
            {
                cout << "End";
            }
        }
    }
}

int main()
{
    int n, m;
    int pre[100000];
    int ino[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    cin >> m;
    for (int j = 0; j < m; j++)
    {
        cin >> ino[j];
    }
    node *root = build_tree_from_traversal(ino, pre, 0, n - 1);
    bfs2(root);
    return 0;
}