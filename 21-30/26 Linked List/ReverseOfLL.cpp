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

void reverse(node *&head)
{
    node *C = head;
    node *P = NULL;
    node *N;
    while (C != NULL)
    {
        //save the next node
        N = C->next;
        //link to the previous node
        C->next = P;
        //Update Current and Previous
        P = C;
        C = N;
    }
    head = P;
}

node *recReverse(node *head)
{
    //base case -> 0 or 1  node
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    //recursive case
    //call on smaller list
    node *Shead = recReverse(head->next);
    //go to the last node of the small linked list
    /*
    node *temp=Shead;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    */
    //to find the temp we can skip this loop because temp is head->next
    node *temp=head->next;
    temp->next=head;
    head->next=NULL;
    return Shead;
}

int main()
{
    node *head;
    cin >> head;
    cout << head;
    head = recReverse(head);
    cout << head;
    return 0;
}