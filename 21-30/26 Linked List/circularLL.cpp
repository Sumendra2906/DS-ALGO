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
    node *n = new node(d);
    n->next = head;
    node *temp = head;
    if (temp != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    else
    {
        n->next = n;
    }
    head = n;
}

void print(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data;
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

//we need to do some operator overloading when we want to get the whole list printed by saying cout << head;
//Without operator overloading we will only get the address of the head as output

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

node *get_node(node *head, int d)
{
    node *temp = head;
    //checking all nodes except last
    while (temp->next != head)
    {
        if (temp->data == d)
        {
            return temp;
        }
        temp = temp->next;
    }
    //check last
    if (temp->data == d)
    {
        return temp;
    }
    return NULL;
}

void delete_node(node *&head, int d)
{
    node *pos = get_node(head, d);
    if (pos == NULL)
    {
        return;
    }
    node *temp = head;
    if (pos == head)
    {
        head = head->next;
    }
    //deleting any other node
    while (temp->next != pos)
    {
        temp = temp->next;
    }
    temp->next = pos->next;
    delete pos;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    print(head);
    delete_node(head,3);
    print(head);
    delete_node(head,5);
    print(head);
    return 0;
}