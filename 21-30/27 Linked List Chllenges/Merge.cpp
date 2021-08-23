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

void insertAtTail(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        tail = head;
        return;
    }
    tail->next = new node(d);
    tail = tail->next;
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

node *mergeLL(node *a, node *b)
{
    node *c;
    node *temp;
    if (a->data < b->data)
    {
        c = a;
        temp=c;
        a = a->next;
    }
    else
    {
        c = b;
        temp=c;
        b = b->next;
    }
    while (a != NULL and b != NULL)
    {
        if (a->data < b->data)
        {
            temp->next = a;
            temp=temp->next;
            a = a->next;
        }
        else
        {
            temp->next = b;
            temp=temp->next;
            b = b->next;
        }
    }
    while (a != NULL)
    {
        temp->next = a;
        temp=temp->next;
        a = a->next;
    }
    while (b != NULL)
    {
        temp->next = b;
        temp=temp->next;
        b = b->next;
    }
    return c;
}

int main()
{
    int t;
    int n1, n2;
    node *a = NULL;
    node *atail = NULL;
    node *b = NULL;
    node *btail = NULL;
    node *c;
    cin >> t;
    int val;
    while (t--)
    {
        cin >> n1;
        for (int i = 0; i < n1; i++)
        {
            cin >> val;
            insertAtTail(a, atail, val);
        }
        cin >> n2;
        for (int i = 0; i < n2; i++)
        {
            cin >> val;
            insertAtTail(b, btail, val);
        }
        c = mergeLL(a, b);
        print(c);
    }
    return 0;
}