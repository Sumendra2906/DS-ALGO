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

//we need to do some operator overloading when we want to get the whole list printed by saying cout << head;
//Without operator overloading we will only get the address of the head as output

ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
    //returning cout object by reference
}

void append(node *&head, node *&tail, int k, int n)
{
    //run a loop n-k+1 times
    int jump = 1;
    node *c = head->next;
    node *prev = head;
    while (jump < (n - k))
    {
        c = c->next;
        prev = prev->next;
        jump++;
    }
    prev->next = NULL;
    node *temp = c;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head = c;
    tail = prev;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int n, k;
    cin >> n;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertAtTail(head, tail, val);
    }
    cin >> k;
    if (k > n)
    {
        cout << head;
    }
    else
    {
        append(head, tail, k, n);
        cout << head;
    }
    return 0;
}