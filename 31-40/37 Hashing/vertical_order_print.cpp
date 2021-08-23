#include <iostream>
#include <vector>
#include <map>
using namespace std;

class node
{
public:
    node *left;
    int data;
    node *right;

    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};
//passing the map by reference
void verticalPrint(node *root, int d, map<int, vector<int>> &m)
{
    if (root == NULL)
    {
        return;
    }
    m[d].push_back(root->data);
    //calling on left
    verticalPrint(root->left, d - 1, m);
    //calling on right
    verticalPrint(root->right, d + 1, m);
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    root->right->right->right = new node(9);
    root->left->right->right = new node(8);

    map<int, vector<int>> m;
    int d = 0;
    verticalPrint(root, d, m);

    for (auto p : m)
    {
        for (auto it : p.second)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}