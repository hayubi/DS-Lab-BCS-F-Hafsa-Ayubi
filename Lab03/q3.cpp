/*3. Reverse in Groups of K
Reverse nodes of a singly linked list in groups of size k.
• Example:
    o Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, with k = 3
    o Output: 3 → 2 → 1 → 6 → 5 → 4 → 8 → 7*/

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        Node()
        {
            data = 0;
            next = NULL;
        }
        Node(int val)
        {
            data = val;
            next = NULL;
        }
};

class SLL
{
    public:
        Node* head;
        SLL() : head(NULL) {}

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

Node* reverseKgrp(Node* &head, int k)
{
    Node* prev = NULL;
    Node* curr = head;
    int counter = 0; //to count first k nodes

    //reversing first k nodes
    while (curr!=NULL && counter<k)
    {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        counter++;
    }

    //curr will now give us (k+1)th node
    if (curr != NULL)
    {
        Node* newhead = reverseKgrp(curr, k); //recursion
        head->next = newhead;
    }

    return prev; //prev...new head of connected ll
}

int main()
{
    SLL ll;
    ll.insertEnd(2);
    ll.insertEnd(3);
    ll.insertEnd(4);
    ll.insertEnd(5);
    ll.insertEnd(6);
    ll.insertEnd(7);
    cout << endl << "Original LL: " << endl;
    ll.display();
    ll.head = reverseKgrp(ll.head, 3);
    cout << endl << "Reversed LL: " << endl;
    ll.display();
}