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

bool detect(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return false;
    }
    node *slow = head;
    node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

bool detectRemove(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return false;
    }
    node *slow = head;
    node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            //take slow to head
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            //here we have found the start of the cycle
            node *n = slow;
            //break cycle
            while (fast->next->next != n)
            {
                fast = fast->next;
            }
            //now fast is at one node before n
            fast->next = NULL;
            return true;
        }
    }
    return false;
}

int main()
{
    node *head;
    cin >> head;
    cout << head;
    return 0;
}