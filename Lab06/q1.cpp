/*Task 1 – Basic Stack Implementation
Implement a stack using arrays. Support the following operations:
1. Push an element
2. Pop an element
3. Peek (top element)
4. Display stack contents
*/

#include <iostream>
using namespace std;

class Stack
{
    private:
        int *arr;
        int tos;
        int capacity;
    
    public:
        Stack(int c)
        {
            capacity = c;
            arr = new int[c];
            tos = -1;
        }

        void push (int data)
        {
            if (tos == capacity-1)
            {
                cout << "Stack Overflow" << endl;
                return;
            }
            tos++;
            arr[tos] = data;
        }

        void pop()
        {
            if (tos == -1)
            {
                cout << "Stack Underflow" << endl;
                return;
            }
            tos--;
        }

        int peek()
        {
            if (tos == -1)
            {
                cout << "Stack Underflow" << endl;
                return 0;
            }
            return arr[tos];
        }

        bool isEmpty() { return (tos == -1); }
        bool isFull() { return (tos == capacity-1); }
        int size() { return (tos+1); }

        void display()
        {
            for (int i=0; i<capacity; i++)
            {
                cout << arr[i] << endl;
            }
        }
};

int main()
{
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "Original Stack: " << endl;
    s.display();
    cout << endl << "After popping: " << endl;
    s.pop();
    s.display();
    s.push(22);
    cout << endl << "Pushing 22 after popping: " << endl;
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << endl << "Top element: " << s.peek() << endl;
}
