#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtHead(node *&head, int d)
{
    if (head == NULL)
    {
        //empty
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

node *take_input()
{
    int d;
    cin >> d;
    node *head = NULL;
    //we can do while cin>>d if we want to take input from a file.
    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }
    return head;
}

ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
    //returning cout object by reference
}

istream &operator>>(istream &is, node *&head)
{
    head = take_input();
    return is;
}

node *mergeLL(node *a, node *b)
{
    //base case
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    //recursive case
    //take new head
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = mergeLL(a->next, b);
    }
    else
    {
        c = b;
        c->next = mergeLL(a, b->next);
    }
    return c;
}

int main()
{
    node *a;
    node *b;
    cin >> a >> b;
    cout << a << b;
    cout << mergeLL(a, b);
    return 0;
}