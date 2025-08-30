/*Task #3:
Design a program to handle marks of students in different courses using a jagged array
(since each student is enrolled in a different number of courses).
=> Input the number of courses each student takes.
=> Dynamically allocate memory for each student accordingly.
=> Calculate and display each student’s average marks.*/

#include <iostream>
using namespace std;

int main()
{
    int numstudents;
    cout << "Enter the number of students: ";
    cin >> numstudents;
    int **students = new int*[numstudents];
    int *courses = new int[numstudents]; // each student's #courses

    for (int i=0; i<numstudents; i++)
    {
        int numcourses;
        cout << "Enter number of courses for student " << i+1 << ": ";
        cin >> numcourses;
        courses[i] = numcourses; // one student has this #courses
        students[i] = new int[numcourses];

        int sum = 0;
        cout << "Enter marks for " << numcourses << " courses: " << endl;
        for(int j=0; j<numcourses; j++)
        {
            cout << "course " << j+1 << ". ";
            cin >> students[i][j];
            sum = sum + students[i][j];
        }
        double avg = static_cast<double>(sum)/numcourses;
        cout << "Average of student " << i+1 << ": " << avg << endl;
    }
    
    for (int i=numstudents-1; i>=0; i--)
    {
        delete[] students[i];
    }
    delete[] students;
    delete[] courses;
}