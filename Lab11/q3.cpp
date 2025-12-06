// Implement the class Hash class having the functionality of insert, delete, search and display using list (built in library for linked list in C++).

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Hash {
    private:
    list<pair<string, string> >* table;
    int size;
    
    int getHash(string key){
        int sum =0;
        for (int i=0; i<key.length();i++)
            sum+= key[i];

        return sum%size;
    }

    public:
    Hash(int size=10): size(size) {table = new list<pair<string, string> >[size]; }
    
    ~Hash() { delete[] table; }

    void insert(string key,string value){
        int index =getHash(key);
        list<pair<string, string> > newList;
        bool keyFound = false;
        
        while (table[index].empty() == false) {
            pair<string, string> front =table[index].front();
            table[index].pop_front();
            if (front.first == key){
                newList.push_front(make_pair(key, value));
                keyFound = true;
            } 
            else {newList.push_front(front); }
        }
        if (keyFound ==false) { newList.push_front(make_pair(key, value));}
        table[index] = newList;
    }
    
    void deleteKey(string key) {
        int index =getHash(key);
        list<pair<string, string> > newList;
        
        while (table[index].empty()== false){
            pair<string, string> front =table[index].front();
            table[index].pop_front();
            if (front.first !=key){
                newList.push_front(front);
            }
        }
        table[index] =newList;
    }
    
    string search(string key){
        int index =getHash(key);
        list<pair<string,string>> temp=table[index];
        
        while (temp.empty() ==false) {
            pair<string, string> front= temp.front();
            temp.pop_front();
            if (front.first== key) {
                return front.second;
            }
        }
        return "not found";
    }
    
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "index "<< i<<": ";
            list<pair<string, string> > temp=table[i];
            while (temp.empty() ==false) {
                pair<string,string> front= temp.front();
                temp.pop_front();
                cout<< front.first << ", " << front.second;
            }
            cout<< endl;
        }
    }
};

int main() 
{
    Hash h(10);
    h.insert("AB", "FAST");
    h.insert("CD", "CS");
    h.insert("EF", "EE");
    cout << "Search AB: " << h.search("AB") << endl;
    h.deleteKey("CD");
    h.display();

}
