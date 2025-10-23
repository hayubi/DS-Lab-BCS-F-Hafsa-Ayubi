/*Task 7 – Application of Stack & Queue (Advanced)
Design a job scheduling system where:
1. Processes (with IDs & priorities) arrive and are stored in a queue.
2. Execution order is determined using a stack (LIFO execution of high-priority tasks).
3. Demonstrate how both queue (arrival order) and stack (execution handling) are
combined.*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Stack
{
    public:
        char *arr;
        int capacity;
        int top;

        Stack(int cap = 0)
        {
            capacity = cap;
            top = -1;
            arr = new char[capacity];
        }

        bool empty() { return top == -1; }

        void push(char n)
        {
            if (top == capacity-1)
            {
                cout << "Stack overflow" << endl;
                return;
            }
            arr[++top] = n;
        }

        char pop()
        {
            if (top<0)
            {
                cout << "Stack underflow" << endl;
                return '\0';
            }
            return arr[top--];
        }

        char peek()
        {
            if (top<0)
                return '\0';
            return arr[top];
        }

        ~Stack()
        {
            delete[] arr;
            arr = nullptr;
        }
};

class queue
{
    public:
        int *arr;   
        int *priority;
        int capacity;
        int size;

        queue(int cap = 0)
        {
            capacity = cap;
            size = 0;
            arr = new int[capacity];
            priority = new int[capacity];
        }

        bool isempty() { return size == 0; }
        bool isfull() { return size == capacity; }

        void enqueue(int id, int p)
        {
            if (isfull())
            {
                cout << "Queue overflow" << endl;
                return;
            }
            arr[size] = id;
            priority[size] = p;
            size++;
        }

        int dequeue()
        {
            if (isempty())
            {
                cout << "queue is empty" << endl;
                return -1;
            }
            int data = arr[0];
            for (int i=0; i < size-1; i++)
            {
                arr[i] = arr[i+1];
            }
            size--;
            return data;
        }

        void display()
        {
            if (isempty())
            {
                cout << "queue is empty" << endl;
                return;
            }
            for (int i=0; i<size; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        ~queue()
        {
            delete[] arr;
            arr = nullptr;
        }
};

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    queue jobQueue(n);
    Stack executionStack(n);

    for (int i=0; i<n; i++)
    {
        int id;
        int priority;
        cout << endl << "Enter process ID: ";
        cin >> id;
        cout << "Enter priority (1: low 2: medium 3: high): ";
        cin >> priority;
        jobQueue.enqueue(id, priority);
    }

    cout << endl << "Processes in queue:" << endl;
    for (int i=0; i<jobQueue.size; i++)
    {
        cout << "ID: " << jobQueue.arr[i] << " | Priority: " << jobQueue.priority[i] << endl;
    }

    // moving high priority to stack
    for (int i=0; i<jobQueue.size; i++)
    {
        if (jobQueue.priority[i] == 3)
        {
            executionStack.push(jobQueue.arr[i]);
        }
    }

    cout << endl << "Executing high priority jobs from stack:" << endl;
    while (!executionStack.empty())
    {
        int process = executionStack.pop();
        cout << "Running process " << process << " (high priority)" << endl;
    }

    cout << endl << "Executing remaining jobs from queue:" << endl;
    for (int i=0; i<jobQueue.size; i++)
    {
        if (jobQueue.priority[i] != 3)
        {
            cout << "Running process " << jobQueue.arr[i] << " (priority " << jobQueue.priority[i] << ")" << endl;
        }
    }
}