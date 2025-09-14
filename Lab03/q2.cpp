/*2. Merge Two Sorted Singly Linked Lists
Implement a function to merge two sorted singly linked lists into one sorted list.
• Example:
    o List A: 1 → 3 → 5
    o List B: 2 → 4 → 6
    o Output: 1 → 2 → 3 → 4 → 5 → 6
• Bonus: Solve without creating new nodes (rearrange pointers).*/

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

Node* mergeLL(Node* &head1, Node* &head2)
{
    Node* dummyhead = new Node(-1); // node!!
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyhead;

    while(ptr1 && ptr2)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    if (ptr1)
        ptr3->next = ptr1;
    else
        ptr3->next = ptr2;

    return dummyhead->next;
}

int main()
{
    SLL ll1;
    ll1.insertEnd(12);
    ll1.insertEnd(19);
    ll1.insertEnd(21);
    cout << "LL1: "; 
    ll1.display();

    SLL ll2;
    ll2.insertEnd(15);
    ll2.insertEnd(17);
    ll2.insertEnd(18);
    ll2.insertEnd(20);
    ll2.insertEnd(25);
    ll2.insertEnd(27);
    cout << "LL2: "; 
    ll2.display();

    SLL ll3;
    ll3.head = mergeLL(ll1.head, ll2.head);
    cout << endl << "Merged Linked List: " << endl;
    ll3.display();
}