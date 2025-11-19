/*Task 5:
Implement Quick Sort using linked list in C++. Define a node for a linked list with integer data
and a pointer to the next node. Write a function to swap two nodes in the linked list. Write a
function to partition the linked list using the last node as the pivot. Implement the Quick Sort
algorithm using the partition function and the swap function. Finally, write a function to print the
sorted linked list. Your implementation should be able to handle empty linked lists and linked lists
with only one node. Test your implementation with a sample linked list containing the following
integers: 10, 7, 8, 9, 1, 5, 3. The expected output after sorting should be: 1 3 5 7 8 9 10.*/

/*Task 5:
Implement Quick Sort using linked list in C++. Define a node for a linked list with integer data
and a pointer to the next node. Write a function to swap two nodes in the linked list. Write a
function to partition the linked list using the last node as the pivot. Implement the Quick Sort
algorithm using the partition function and the swap function. Finally, write a function to print the
sorted linked list. Your implementation should be able to handle empty linked lists and linked lists
with only one node. Test your implementation with a sample linked list containing the following
integers: 10, 7, 8, 9, 1, 5, 3. The expected output after sorting should be: 1 3 5 7 8 9 10.*/

#include <iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node* next;
        Node(int x) 
        { 
            data = x; 
            next = NULL; 
        }
};

void pushfr(Node*& head, int x) 
{
    Node* n = new Node(x);
    n->next = head;
    head = n;
}

void swapNodes(Node* a, Node* b) 
{
    int t = a->data;
    a->data = b->data;
    b->data = t;
}

Node* getTail(Node* head) 
{
    if (!head) 
        return NULL;
    while (head->next) 
        head = head->next;
    return head;
}

Node* partition(Node* first, Node* last) 
{
    int pivot = last->data;
    Node* i = first;
    Node* j = first;
    while (j != last) 
    {
        if (j->data < pivot) 
        {
            swapNodes(i,j);
            i = i->next;
        }
        j = j->next;
    }
    swapNodes(i,last);
    return i;
}

void quickSort(Node* first, Node* last) 
{
    if (!first || first == last) 
        return;

    Node* pivot = partition(first,last);
    Node* prevPivot = NULL;
    Node* temp = first;
    while (temp != pivot) 
    {
        prevPivot = temp;
        temp = temp->next;
    }

    if (prevPivot && first != pivot)
        quickSort(first,prevPivot);
    if (pivot->next)
        quickSort(pivot->next,last);
}

void printlist(Node* head) 
{
    while (head) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() 
{
    Node* head = NULL;
    pushfr(head,3);
    pushfr(head,5);
    pushfr(head,1);
    pushfr(head,9);
    pushfr(head,8);
    pushfr(head,7);
    pushfr(head,10);
    Node* tail = getTail(head);
    quickSort(head,tail);
    cout << "Sorted list:   ";
    printlist(head);
}