/*Task 4 – Circular Queue
Implement a circular queue using arrays. Handle the following conditions correctly:
1. Enqueue when rear wraps around
2. Dequeue when front moves ahead
3. Prevent overflow when queue is full*/

#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue 
{
    private:
        int items[SIZE];
        int front, rear;

    public:
        CircularQueue() 
        {
            front = -1;
            rear = -1;
        }

        bool isEmpty() { return (front == -1); }
        bool isFull() 
        {
            if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
                return true;
            return false;
        }

        void enqueue(int element) 
        {
            if (isFull()) 
            {
                cout << "Queue is FULL" << endl;
                return;
            }

            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << "Inserted: " << element << endl;
        }

        void dequeue() 
        {
            if (isEmpty()) 
            {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Deleted: " << items[front] << endl;

            if (front == rear) //one elmt
            {
                front = -1;
                rear = -1;
            } 
            else
                front = (front+1) % SIZE;
        }

        void display() 
        {
            if (isEmpty()) 
            {
                cout << "Queue is empty" << endl;
                return;
            }

            cout << "Queue elements: ";
            int i = front;
            while (true) 
            {
                cout << items[i] << " ";
                if (i == rear)
                    break;
                i = (i+1) % SIZE;
            }
            cout << endl;
        }
};

int main() 
{
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.enqueue(70);
    q.display();
}