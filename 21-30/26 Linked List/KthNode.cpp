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

node *kth_node(node *head, int k)
{
    if (head == NULL or k == 1)
    {
        return head;
    }
    node *slow = head;
    node *fast = head;
    int jump = 0;
    //go k steps ahead
    while (jump < k)
    {
        fast = fast->next;
        jump++;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    node *head;
    cin >> head;
    cout << head;
    int k;
    cin >> k;
    cout << kth_node(head, k)->data;
    return 0;
}