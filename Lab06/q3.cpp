/*Task 3 – Simple Queue Implementation
Implement a linear queue using arrays with the following operations:
1. Enqueue
2. Dequeue
3. Display queue contents
4. Check if queue is empty/full */

#include <iostream>
using namespace std;

class Queue 
{
    private:
        int *arr;
        int capacity;
        int size;

    public:
        Queue(int c) 
        {
            capacity = c;
            arr = new int[capacity];
            size = 0;
        }

        bool isEmpty() { return size == 0; }
        bool isFull() { return size == capacity; }

        void enqueue(int x)
        {
            if (isFull())
            {
                cout << "Queue is full. Cannot push " << x << endl;
                return;
            }
            arr[size] = x;
            size++;
        }

        void dequeue()
        {
            if (isEmpty())
            {
                cout << "Queue is empty" << endl;
                return;
            }
            for (int i=1; i<size; i++)
            {
                arr[i-1] = arr[i];
            }
            size--;
        }

        void display()
        {
            if (isEmpty())
            {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Queue contents: " << endl;
            for (int i=0; i<size; i++)
            {
                cout << arr[i] << endl;
            }
            cout << endl;
        }
};

int main()
{
    Queue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << endl << "Original Queue: " << endl;
    q.display();
    cout << "After Dequeue: " << endl;
    q.dequeue();
    q.dequeue();
    q.display();
}