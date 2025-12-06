/*Task # 2: Some ABC university students want to develop an ASCII code-based dictionary app for their Final Year
Project. This app should allow the users to perform the following operations:
a) Add_Record () This function will take a string input from user and add into the dictionary. For adding
the string user will use a unique hash function k MOD 100 (table size must be 100, for k user will calculate
the SUM of ASCII character of that word).
b) Word_Search () User will only pass a single string. If string is not available then generate an error
message.
c) Print_Dictionary () Users can also display the complete dictionary.
Note: Use Separate Chaining in case of collisions.
Output:
 search key AB: FASTNU
 key EF deleted successfully !
 index 31: (AB, FASTNU)
 index 35: (CD, CS)*/

#include <iostream>
#include <string>
using namespace std;

class Node 
{
    public:
        string key;
        string value;
        Node* next;
        Node(string k, string v) 
        {
            key = k;
            value = v;
            next = NULL;
        }
};

class Dictionary {
private:
    Node* table[100];

    int hashFunction(string str) 
    {
        int sum = 0;
        for (int i=0; i < str.length(); i++)
            sum += (int)str[i];
        return sum % 100;
    }

public:
    Dictionary() 
    {
        for (int i=0; i< 100; i++)
            table[i] = NULL;
    }

    void Add_Record(string key, string value) 
    {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);
        newNode->next= table[index];
        table[index]= newNode;
    }

    void Word_Search(string key) 
    {
        int index = hashFunction(key);
        Node* current= table[index];

        while (current != NULL) 
        {
            if (current->key == key) 
            {
                cout << "search key " << key << ": " << current->value << endl;
                return;
            }
            current = current->next;
        }
        cout << "Error. " << key << " not found" << endl;
    }

    void Delete_Word(string key) 
    {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = NULL;
        while (current != NULL) 
        {
            if (current->key == key) 
            {
                if (prev == NULL)
                    table[index] = current->next;
                else
                    prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Error. " << key << " not found" << endl;
    }

    void Print_Dictionary() 
    {
        for (int i = 0; i < 100; i++) {
            if (table[i] != NULL) {
                cout << "index " << i << ": ";
                Node* current = table[i];
                while (current != NULL) 
                {
                    cout << "(" << current->key << ", " << current->value << ")";
                    if (current->next != NULL) cout << " -> ";
                    current = current->next;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Dictionary dict;
    dict.Add_Record("AB", "FASTNU");
    dict.Add_Record("CD", "CS");
    dict.Add_Record("EF", "EEE");
    dict.Word_Search("AB");
    dict.Delete_Word("EF");
    dict.Print_Dictionary();
}