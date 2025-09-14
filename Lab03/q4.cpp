/*4. Josephus Problem using Circular Linked List
Use a circular linked list to solve the Josephus problem:
• N people stand in a circle, eliminating every k-th person until only one survives.
• Input: N = 7, k = 3
• Output: Position of survivor.
• Hint: Use circular traversal and deletion.*/

#include <iostream>
using namespace std;

class Node
{
    public: 
        int data;
        Node* next;

        Node() : data(0), next(NULL) {}
        Node(int val)
        {
            data = val;
            next = NULL;
        }
};

class CircularLL
{
    public: 
        Node* head;
        CircularLL() : head(NULL) {}

        void insertEnd(int val)
        {
            Node* newnode = new Node(val);
            if (head == NULL)
            {
                head = newnode;
                newnode->next = head;
                return;
            }

            Node* temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }

        void deleteStart()
        {
            if (head == NULL) // ll empty
            {
                return;
            }

            Node* temp = head; //to delete
            Node* tail = head; //for traversing
            while (tail->next != head)
            {
                tail = tail->next;
            }
            head = head->next; //move head one ahead
            tail->next = head;
            delete temp;  
        }

        void deleteAnywhere(int pos)
        {
            if (head == NULL)
            {
                return;
            }
            if (pos == 0)
            {
                deleteStart();
                return;
            }
            
            //traversing till pos-1
            int currpos = 0;
            Node* prev = head;
            while (currpos != (pos-1))
            {
                prev = prev->next;
                currpos++;
            }

            Node* temp = prev->next; //to be deleted
            prev->next = prev->next->next; //skip the del node and prev is now pointing to new next(skipped) node
            delete temp;  
        }

        void display()
        {
            Node* temp = head;
            do 
            {
                cout << temp->data << " -> ";
                temp = temp -> next;
            } while(temp != head); 
            cout << endl;
        }
};

int josephus(int n, int k)
{
    if (n<=0 || k<=0) 
    {
        return -1;
    }

    CircularLL cll;
    for (int i=1; i<=n; i++)
    {
        cll.insertEnd(i);
    }
    cout << "Original Linked List: " << endl;
    cll.display();

    int ncount=n;
    while (ncount != 1)
    {
        for (int kcount=1; kcount<k; kcount++)
        {
            cll.head = cll.head->next;
        }
        cll.deleteStart();
        ncount--;
    }
    
    if (cll.head)
        return cll.head->data;
    else
        return -1;
}

int main()
{
    int n, k;
    cout << "Enter number of people: ";
    cin >> n;
    cout << "Enter k position: ";
    cin >> k;
    int result = josephus(8,3);
    cout << "survivor: " << result << endl;
}