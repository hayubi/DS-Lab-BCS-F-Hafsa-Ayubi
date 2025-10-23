/*Task 2 – Stack with Linked List
Implement a stack using linked lists. Demonstrate its use with a real-life example (e.g., browser
history navigation).*/

#include <iostream>
#include <string>
using namespace std;

class Node 
{
    public:
        string url;
        Node* next;

        Node(string u) 
        {
            url = u;
            next = NULL;
        }
};

class BrowserHistory 
{
    private:
        Node* top;
        int count;

    public:
        BrowserHistory() 
        {
            top = NULL;
            count = 0;
        }

        bool isEmpty() { return top == NULL; }
        int size() { return count; }

        void push(string s) 
        {
            Node* temp = new Node(s);
            temp->next = top;
            top = temp;
            count++;
            cout << "Visited: " << s << endl;
        }

        string pop() 
        {
            if (top == NULL) 
            {
                cout << "No previous history" << endl;
                return "";
            }

            Node* temp = top;
            string site = temp->url;
            top = top->next;
            count--;
            delete temp;

            if (top != NULL)
                cout << "Went back to: " << top->url << endl;
            else
                cout << "No more history!" << endl;
            return site;
        }

        string peek() 
        {
            if (top == NULL) 
            {
                cout << "No page currently open!" << endl;
                return "";
            }
            return top->url;
        }
};

int main() 
{
    BrowserHistory bh;
    bh.push("www.google.com");
    bh.push("www.youtube.com");
    bh.push("www.gmail.com");
    bh.push("www.github.com");

    cout << "Current Page: " << bh.peek() << endl;
    bh.pop();
    cout << "Current Page after going back: " << bh.peek() << endl;
}