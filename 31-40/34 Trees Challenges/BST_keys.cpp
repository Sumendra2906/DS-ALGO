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

void printRange(node* root,int k1,int k2){
    
}


int main()
{
    node *root = NULL;
    int t,n;
    cin >> t;
    int data;
    int k1,k2;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> data;
            root = insertinBST(root, data);
        }
        cin >> k1;
        cin >> k2;
    }
    

    return 0;
}