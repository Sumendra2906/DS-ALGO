#include <iostream>
#include <cstring>
using namespace std;

//seperate chaining method

template <typename T>
class Node
{
public:
    string key;
    T value;
    Node<T> *next;

    Node(string key, T val)
    {
        this->key = key;
        value = val;
        next = NULL;
    }
    //make a destructor to avoid memory leak when we are deleting a pointer
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class HashTable
{
    Node<T> **table;
    //pointer to an array of pointers
    int current_size;
    int table_size;

    int hashFn(string key)
    {
        int idx = 0;
        int p = 1;
        for (int j = 0; j < key.length(); j++)
        {
            idx = idx + (key[j] * p) % table_size;
            idx = idx % table_size;
            p = p * 27 % table_size;
            //doing mod again and again to prevent overflow from int
        }
        return idx;
    }

    void rehash()
    {
        Node<T> **oldTable = table;
        int old_size = table_size;
        table_size = 2 * table_size; //idealy we should find the next prime number
        table = new Node<T> *[table_size];

        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
        current_size = 0;

        //shift the elements
        for (int i = 0; i < old_size; i++)
        {
            Node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                //this will insert in the table
                //but since it iss member of our class so it will be inserted in the new table
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            if (oldTable[i] != NULL)
            {
                //delete it since we have already copied the ith row
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int ts = 7)
    {
        table_size = ts;
        //initializing a table of size 7 by default
        table = new Node<T> *[table_size];
        current_size = 0;
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T value)
    {
        int idx = hashFn(key);
        Node<T> *n = new Node<T>(key, value);
        //making a chain
        //insert at the head of the linked list with id = idx
        n->next = table[idx]; //now n is pointing to old head
        table[idx] = n;
        current_size++;

        //rehashing
        float load_factor = current_size / (table_size * 1.0);
        if (load_factor > 0.7)
        {
            //make new larger table and store there
            rehash();
        }
    }

    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Bucket " << i << "->";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "-> ";
                temp = temp->next;
                /* code */
            }
            cout << endl;
        }
    }
    T *search(string key)
    {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &temp->value;
            }
            temp = temp->next;
        }
        return NULL;
        //returning a pointer because of NULL
    }
    /*
    void erase(string key)
    {   
    }
    */

   T& operator[](string key){
       //search for key
       T* f = search(key);
       if(f==NULL){
           //insert key,value(garbage)
           T garbage;
           insert(key,garbage);
           f=search(key);
       }
       return *f;
   }
};