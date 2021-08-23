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

int length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

//passing a pointer by reference
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

//inserting after p positions
void insertInMiddle(node *&head, int d, int p)
{
    if (head == NULL or p == 0)
    {
        insertAtHead(head, d);
        return;
    }
    if (p > length(head))
    {
        insertAtTail(head, d);
        return;
    }
    //make p-1 jumps
    int jump = 1;
    node *temp = head;
    while (jump < p)
    {
        jump++;
        temp = temp->next;
    }
    node *n = new node(d);
    n->next = temp->next;
    temp->next = n;
}

void deleteHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}

void deleteTail(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *prev = head;
    while (prev->next->next != NULL)
    {
        prev = prev->next;
    }
    node *tail = prev->next;
    delete tail;
    prev->next = NULL;
}

//deleting at pth position
void deleteMiddle(node *&head, int p)
{
    if (head == NULL)
    {
        return;
    }
    if (p == 0)
    {
        deleteHead(head);
        return;
    }
    if (p >= length(head))
    {
        deleteTail(head);
        return;
    }
    node *prev = head;
    int jumps = 1;
    //make p-1 jumps to go the prev element
    while (jumps < p)
    {
        jumps++;
        prev = prev->next;
    }
    node *temp = prev->next;
    prev->next = temp->next;
    delete temp;
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

int search(node *head, int key, int i)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == key)
    {
        return i;
    }
    return search(head->next, key, i + 1);
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

int main()
{
    node *head;
    node *head2;
    cin >> head >> head2;
    /*
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    print(head);
    insertInMiddle(head, 68, 8);
    insertAtTail(head, 69);
    print(head);
    deleteHead(head);
    print(head);
    deleteTail(head);
    print(head);
    deleteMiddle(head, 2);
    print(head);
    //cout << length(head);
    cout << search(head, 68,0);
    */
    cout << head << head2;

    return 0;
}