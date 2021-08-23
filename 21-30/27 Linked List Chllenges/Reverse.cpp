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

void insertAtTail(node *&head, int *&tail, int d)
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

void reversek(node *head, int n, int k)
{
    int jump = 1;
    node *nex;
    node *temp = head;
    while (temp->next != NULL)
    {
        if (jump % k == 0)
        {
            nex = temp->next;
            temp->next = NULL;
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
        temp = temp->next;
        jump++;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    node *head;
    node *tail;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertAtTail(head, tail, val);
    }
    return 0;
}