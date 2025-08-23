/*Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases.*/

#include<iostream>
using namespace std;

class Box 
{
    private:
        int* value;

    public:
        Box() 
        {
            value = new int(0);
        }

        Box(int v) 
        {
            value = new int(v);
        }

        Box(const Box& b) 
        {
            value = new int(*(b.value));
        }

        Box& operator=(const Box& b) 
        {
            if (this != &b) 
            {
                delete value;
                value = new int(*(b.value));
            }
            else
                return *this;
        }

        ~Box() 
        {
            delete value;
        }

        void setValue(int v) { *value = v; }
        int getValue() const { return *value; }

        void display(const string& name) const 
        {
            cout << name << " value: " << *value << endl;
        }
};


int main() 
{
    Box b1(22);
    b1.display("b1");
    Box b2 = b1;
    b2.display("b2");

    cout << endl << "After modification (b1 set to 33): " << endl;
    b1.setValue(33);
    b1.display("b1"); //changed
    b2.display("b2"); //unchanged

    Box b3;
    b3 = b1;
    cout << endl;
    b3.display("b3");

    cout << endl << "After modification (b1 set to 44): " << endl;
    b1.setValue(44);
    b1.display("b1"); //changed
    b3.display("b3"); //unchanged
}