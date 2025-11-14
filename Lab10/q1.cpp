/*Task#1: Task one create the min max heap from values 8, 7 , 6 ,5 , 4 the tree looks
like below:
Now change write a function that can take the two parameters one index and other
value , after that update that value store at that index i with the values provided in
parameters void update_key(int i, int new_val); also write the delete function
to delete element from heap.*/

#include <iostream>
using namespace std;
#define maxsize 100

class MaxHeap 
{
    public:
        int heap[maxsize];
        int size;
        MaxHeap() {size = 0;}
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return 2*i+1; }
        int right(int i) { return 2*i+2; }

        void heapifyUp(int i) 
        {
            while (i!=0 && heap[parent(i)]<heap[i]) 
            {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void heapifyDown(int i) 
        {
            int largest=i;
            int l=left(i);
            int r=right(i);
            if (l<size && heap[l] > heap[largest])
                largest = l;
            if (r<size && heap[r] > heap[largest])
                largest = r;
            if (largest!=i) 
            {
                swap(heap[i], heap[largest]);
                heapifyDown(largest);
            }
        }

        void insert(int val) 
        {
            if (size >= maxsize) 
            {
                cout << "Heap overflow" << endl;
                return;
            }
            heap[size]=val;
            size++;
            heapifyUp(size-1);
        }

        void update_key(int index, int new_val) 
        {
            if (index<0 || index>=size) 
            {
                cout << "invalid index" << endl;
                return;
            }

            int old_val = heap[index];
            heap[index] = new_val;
            if (new_val>old_val)
                heapifyUp(index);
            else
                heapifyDown(index);
        }

        void delete_key(int index) 
        {
            if (index<0 || index>=size) 
            {
                cout << "Invalid index!" << endl;
                return;
            }
            heap[index] = heap[size - 1];
            size--;
            heapifyUp(index);
            heapifyDown(index);
        }

        void print() 
        {
            for (int i=0; i<size; i++)
                cout << heap[i] << " ";
            cout << endl;
        }
};

int main() 
{
    MaxHeap h;
    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);
    h.print();
    h.update_key(3, 12);
    h.delete_key(1);
    h.print();
}