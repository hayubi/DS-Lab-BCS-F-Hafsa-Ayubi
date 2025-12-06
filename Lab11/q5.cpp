/*Task # 5: Implement a C++ class StudentHashTable to manage student records in a hash table with a size of 15. Use
quadratic probing for collision resolution with the formula (index + attempt^2) % table size.Implement the
function InsertRecord that takes a student&#39;s roll number and name, inserting the record into the hash table
using quadratic probing.Implement the function SearchRecord that takes a roll number, searches for the
corresponding record using quadratic probing, and prints the student&#39;s name if found; otherwise, print a
&quot;Record not found&quot; message.*/

#include <iostream>
#include <string>
using namespace std;

class Student
{
    public:
        int rollNumber;
        string name;
        Student(int rollNumber,string name): rollNumber(rollNumber),name(name) {}
};

class StudentHashTable {
    private:
        Student** table;
        int tableSize;
        int hash(int rollNumber) {return rollNumber % tableSize; }

    public:
    StudentHashTable(int size=15): tableSize(size) {
        table = new Student*[tableSize];
        for (int i=0; i<tableSize;i++)
            table[i]= nullptr;
    }

    void insertRecord(int rollNumber, string name) {
        int startIndex = hash(rollNumber);
        int attempt = 0;
        while (attempt < tableSize) {
            int index = (startIndex+ attempt*attempt) %tableSize;
            if (table[index] == nullptr) {
                table[index] = new Student(rollNumber,name);
                return;
            }
            attempt++;
        }
        cout << "cannot insert as table full" << endl;
    }

    void searchRecord(int rollNumber) {
        int startIndex = hash(rollNumber);
        int attempt = 0;
        while (attempt < tableSize) {
            int index = (startIndex+attempt*attempt)%tableSize;
            if (table[index] == nullptr){
                cout <<"Record not found"<<endl;
                return;
            }
            else if (table[index]->rollNumber ==rollNumber) {
                cout <<"student Name: "<< table[index]->name<< endl;
                return;
            }
            attempt++;
        }
        cout <<"Record not found" << endl;
    }
};
int main() 
{
    StudentHashTable table;
    table.insertRecord(191, "manahil");
    table.insertRecord(116, "umna");
    table.insertRecord(101, "asra");
    table.searchRecord(101);
    table.searchRecord(131);
    table.searchRecord(999);
}