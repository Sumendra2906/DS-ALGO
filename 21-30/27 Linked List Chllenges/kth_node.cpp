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
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
    //returning cout object by reference
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
    node *head = NULL;
    node *tail = NULL;
    int val;
    cin >> val;
    while (val != -1)
    {
        insertAtTail(head, tail, val);
        cin >> val;
    }
    int k;
    cin >> k;
    cout << kth_node(head, k)->data;
    return 0;
}