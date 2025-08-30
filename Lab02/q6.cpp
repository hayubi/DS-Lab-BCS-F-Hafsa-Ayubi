/*Task #6:
Implement a Safe Pointer class to wrap around an integer pointer.
=> Provide methods for setValue(), getValue(), and release().
=> Demonstrate the class by storing marks of 5 students and printing them safely without
direct pointer manipulation.*/

#include <iostream>
using namespace std;

class SafePointer 
{
    private:
        int *marks;

    public: 
        SafePointer() : marks(new int(0)) {} //one int only
        SafePointer(int m)
        {
            marks = new int[m];
        }

        ~SafePointer()
        {
            delete marks;
        }

        SafePointer(const SafePointer &sp)
        {
            marks = new int;
            *marks = *sp.marks;
        }

        SafePointer& operator=(const SafePointer &sp)
        {
            if (this != &sp)
            {
                delete marks;
                marks = new int(*sp.marks);
            }
            return *this;
        }

        void setvalue(int a)
        {
            *marks = a;
        }

        int getvalue() { return *marks; }
        void release() //to free memory anywhere in bw code
        {
            delete marks;
            marks = nullptr; //prevents double deletion bcz destructor also present
        }
};

int main()
{
    SafePointer students[5];
    cout << "Enter marks for 5 students: " << endl;
    for (int i=0; i<5; i++)
    {
        cout << i+1 << ". ";
        int stmarks;
        cin >> stmarks;
        students[i].setvalue(stmarks);
    }
    for (int i=0; i<5; i++)
    {
        cout << "Student " << i+1 << ": " << students[i].getvalue() << endl;
    }
}