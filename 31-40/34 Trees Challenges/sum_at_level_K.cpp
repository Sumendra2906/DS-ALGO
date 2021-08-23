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
    int data,children;
    while(cin>>data){
    cin >> children;
    node *root = new node(data);
    }
}



void print_kth_level(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    //call on it's children
    print_kth_level(root->left, k - 1);
    print_kth_level(root->right, k - 1);
    return;
}

int main()
{
    node *root = buildTree();
    return 0;
}