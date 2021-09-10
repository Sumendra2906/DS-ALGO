#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool terminal;

    Node(char d)
    {
        data = d;
        terminal = false;
    }
};

class Trie
{
    Node *root;
    int cnt;

public:
    Trie()
    {
        root = new Node('\0');
        cnt = 0;
    }

    void insert(char *w)
    {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                Node *np = new Node(ch);
                temp->children[ch] = np;
                temp = np;
            }
        }
        temp->terminal = true;
    }

    bool find(char *w)
    {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                return false;
            }
        }
        return temp->terminal;
    }
};

int main()
{
    return 0;
}