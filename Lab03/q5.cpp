/*5. Convert Between Linked List Types
Implement functions for conversion:
1. Convert a singly linked list into a doubly linked list.
2. Convert a singly linked list into a circular linked list.
• Demonstrate both conversions with sample input lists.*/

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;

        Node() : data(0), next(NULL), prev(NULL) {}
        Node(int val)
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
};

class SinglyLL
{
    public:
        Node* head;
        SinglyLL() : head(NULL) {}

        void insertEnd(int val)
        {
            Node* newnode = new Node(val);
            if (head == NULL)
            {
                head = newnode;
                return;
            }
            
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }

        void display()
        {
            Node* temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout  << "NULL" << endl;
        }
};

class DoublyLL
{
    public:
        Node* head;
        Node* tail;
        DoublyLL() : head(NULL), tail(NULL) {}

        void insertEnd(int val)
        {
            Node* newnode = new Node(val);
            if (tail == NULL)
            {
                head = newnode;
                tail = newnode;
                return;
            }

            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            return;
        }

        void display()
        {
            Node* temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << endl;
        }
};

DoublyLL singlyToDoubly(SinglyLL &sll)
{
    DoublyLL dll;
    if (sll.head == NULL) // empty sll
    {
        return dll;
    }

    dll.head = sll.head;
    Node* prev = NULL;
    Node* curr = sll.head;

    while (curr != NULL)
    {
        curr->prev = prev;
        prev = curr;
        curr = curr->next; 
    } 
    dll.tail = prev; 
    return dll;
}

Node* singlyToCircular(SinglyLL &sll)
{
    if (sll.head == NULL) 
    {
        return NULL;
    }

    Node* temp = sll.head;
    while (temp->next != NULL && temp->next != sll.head)
    {
        temp = temp->next;
    }
    temp->next = sll.head;
    return sll.head;
}

void printCircular(Node* head, int limit)
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node* temp = head;
    int cycles = 0;
    do
    {
        do //one full cycle
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cycles++;
    } while (cycles < limit);
    cout << "......" << endl;
}

int main()
{
    SinglyLL sll;
    int size;
    cout << "Enter size of singly list: ";
    cin >> size;
    cout << "Enter " << size << " values: " << endl;
    for (int i=0; i<size; ++i)
    {
        int x; 
        cin >> x;
        sll.insertEnd(x);
    }
    cout << "Singly:  ";
    sll.display();
            
    int choice;
    do 
    {
        cout << endl << "What do you want convert Singly LL to?  1. Doubly | 2. Circular | 0. Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            DoublyLL dll = singlyToDoubly(sll);
            cout << endl << "Singly LL converted to Doubly LL:  ";
            dll.display();
        }
        else if (choice == 2)
        {
            Node* newhead = singlyToCircular(sll);
            int lim;
            cout << "How many cycles do you want to print of circular LL? ";
            cin >> lim;
            cout << endl << "Singly LL converted to Circular:  ";
            printCircular(newhead, lim);
        }
        else 
            return 0;
    } while (choice != 0);
}