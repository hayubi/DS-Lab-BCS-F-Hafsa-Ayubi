/*6. Flatten a Multilevel Linked List
Each node has:
    • next pointer (normal linked list connection).
    • child pointer (points to another linked list).
Write a function to flatten the structure so that all nodes appear in a single-level list.
• Example:
• 1 → 2 → 3
•      |
•      4 → 5
Output: 1 → 2 → 4 → 5 → 3*/

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* child;

        Node() : data(0), next(NULL), child(NULL) {}
        Node(int val)
        {
            data = val;
            next = NULL;
            child =NULL;
        }
};

class LL
{
    public:
        Node *head;
        LL() : head(NULL) {}

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

        void setchildptr(int pos, Node* childhead) 
        {
            Node* temp = head;
            int currpos=0;
            while (temp != NULL && currpos<pos) 
            {
                temp = temp->next;
                currpos++;
            }
            if (temp != NULL) 
            {
                temp->child = childhead;
            }
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

Node* flatten(Node* head) 
{
    if (head == NULL) 
    {
        return NULL;
    }

    Node* curr = head;
    Node* tail = head;
    while (curr != NULL) 
    {
        Node* nextNode = curr->next;
        if (curr->child != NULL) 
        {
            Node* childhead = curr->child;
            Node* childtail = flatten(childhead);
            curr->next = childhead;
            curr->child = NULL;
            childtail->next = nextNode;
            tail = childtail;
        } 
        else 
        {
            tail = curr;
        }
        curr = nextNode;
    }
    return tail;
}

int main() 
{
    LL top;
    top.insertEnd(1);
    top.insertEnd(2);
    top.insertEnd(9);
    top.insertEnd(3);
    cout << endl << "Top LL:" << endl;
    top.display();

    LL child;
    child.insertEnd(4);
    child.insertEnd(5);
    cout << endl << "Child LL:" << endl;
    child.display();

    top.setchildptr(2, child.head);
    cout << endl << "Flattened LL: " << endl;
    flatten(top.head);
    top.display();
}