/*1. Palindrome Check in Singly Linked List
Write a program to check if a singly linked list is a palindrome.
• Input: A singly linked list of integers.
• Output: true if the list reads the same forward and backward, false otherwise.*/

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

class SLinkedList
{
    public:
        Node *head;
        SLinkedList() : head(NULL) {}

        void insertStart(int val)
        {
            Node* newnode = new Node(val);
            newnode->next = head;
            head = newnode;
        }

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

bool isPalindrome(Node* head)
{
    //find middle element
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //slow is now pointing to middle element
    //break the ll in middle
    Node* curr = slow->next;
    Node* prev = slow;
    slow->next = NULL;

    //reverse second half of ll
    while(curr)
    {
        Node* nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }

    //check if 2 ll are equal
    Node* head1 = head;
    Node* head2 = prev;
    while(head2)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

int main()
{
    SLinkedList ll;
    ll.insertEnd(2);
    ll.insertEnd(3);
    ll.insertEnd(4);
    ll.insertEnd(4);
    ll.insertEnd(3);
    ll.insertEnd(2);
    ll.insertEnd(2);
    ll.display();
    if (isPalindrome(ll.head))
        cout << "true. Is a palindrome";
    else
        cout << "false. Not a palindrome";
}