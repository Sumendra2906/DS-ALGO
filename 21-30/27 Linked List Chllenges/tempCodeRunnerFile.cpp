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

//passing a pointer by reference

void insertAtTail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//we need to do some operator overloading when we want to get the whole list printed by saying cout << head;
//Without operator overloading we will only get the address of the head as output

ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
    //returning cout object by reference
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
    int t;
    int n1, n2;
    node *a = NULL;
    node *b = NULL;
    node *c;
    cin >> t;
    int val;
    while (t--)
    {
        cin >> n1;
        for (int i = 0; i < n1; i++)
        {
            cin >> val;
            insertAtTail(a, val);
        }
        cin >> n2;
        for (int i = 0; i < n2; i++)
        {
            cin >> val;
            insertAtTail(b, val);
        }
        c = mergeLL(a, b);
        cout << c;
    }
    return 0;
}