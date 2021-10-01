#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;  // going left means 0
    Node *right; //going right means 1;
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    //insert function
    void insert(int n)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->left == NULL)
                {
                    temp->left = new Node();
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new Node();
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    //m@x xor helper function
    int max_xor_helper(int v)
    {
        int current_max = 0;
        //extract the bits
        Node *temp = root;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (v >> j) & 1;
            if (bit == 0)
            {
                //go right
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    current_max += (1 << j);
                }
                //go left
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                //go left
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    current_max += (1 << j);
                }
                //go right
                else
                {
                    temp = temp->right;
                }
            }
        }
        cout<< current_max;
        return current_max;
    }
    int max_xor(int *input, int n)
    {
        int mmax = 0;
        for (int i = 0; i < n;i++)
        {
            int val = input[i];
            insert(val);
            int curr = max_xor_helper(val);
            cout << curr;
            mmax = max(mmax, curr);
        }
        return mmax;
    }
};

int main()
{
    int input[] = {3,10,5,25,2,8};
    Trie t;
    cout << t.max_xor(input,6);
    return 0;
}