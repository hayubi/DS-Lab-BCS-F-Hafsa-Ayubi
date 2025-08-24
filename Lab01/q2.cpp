/*Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records,
complete with a shallow copy implementation? Define attributes such as student name, exam
date, and score within the class, and include methods to set these attributes and display exam
details. As part of this exercise, intentionally omit the implementation of the copy constructor and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
shallow copy, and observe any resulting issues?*/

#include <iostream>
#include <cstring>
using namespace std;

class Exam 
{
    private:
        char* stname;
        char* examdate;
        int score;

    public:
        Exam(const char* n, const char* ed, int s) 
        {
            stname = new char[sizeof(n)+1];
            strcpy(stname, n);
            examdate = new char[sizeof(ed)+1];
            strcpy(examdate, ed);
            score = s;
        }

        void setscore(int s) { score=s; }

        void setStname(const char* n) 
        {
            delete[] stname;
            stname = new char[sizeof(n)+1];
            strcpy(stname, n);
        }
        void setdate(const char* date) 
        {
            delete[] examdate;
            examdate = new char[sizeof(date)+1];
            strcpy(examdate, date);
        }

        void displayDetails() const 
        {
            cout << "Student Name: " << stname << endl;
            cout << "Exam Date: " << examdate << endl;
            cout << "Score: " << score << endl;
        }

        ~Exam() 
        {
            delete[] stname;
            delete[] examdate;
        }
};

int main() 
{
    Exam e1("Hafsa", "2-04-2025", 83);
    cout << "Exam1 details: " << endl;
    e1.displayDetails();
    
    //shallow copy by default
    Exam e2 = e1;
    cout << endl << "Exam2 details: " << endl;
    e2.displayDetails();

    e2.setStname("Umna"); //changes in e1 too
    e2.setscore(98); //wont change

    cout << endl << "After making changes: " << endl;
    cout << "Exam2 details: " << endl;
    e2.displayDetails();

    cout << endl << "Exam1 details: " << endl;
    e1.displayDetails();
    // because of shallow copy, both e1 and e2 share same address therefore modification of name in e2 will change name of e1 too.
}