/*Task # 1
Suppose you are working on a program that needs to store a large number of strings, with the possibility of
duplicate strings. You decide to use chain hashing to efficiently store and retrieve the strings, but you want
to ensure that collisions are avoided as much as possible. Your hash function simply takes the sum of the
ASCII values of the characters in the string and returns the remainder after dividing by the number of
buckets. You decide to implement the hash table using a linked list for each bucket.
Input and output:
HashTable myhash;
[hine: key is A]
myhash.insert(&quot;A&quot;,&quot;aaaaa&quot;);
myhash.insert(&quot;B&quot;,&quot;bbbbb&quot;);
myhash.insert(&quot;C&quot;,&quot;ccccc&quot;);
myhash.insert(&quot;A&quot;,&quot;zzzzz&quot;);*/

#include <iostream>
using namespace std;

struct Node
{
    string key;
    string value;
    Node *next;
};
class HashTable
{
    Node *table[10];

    int hashFunc(string key)
    {
        int sum=0;
        for (int i=0; i<key.length(); i++)
            sum += key[i];
        return sum%10;
    }

public:
    HashTable()
    {
        for (int i=0; i<10; i++)
            table[i] = NULL;
    }

    void insert(string key, string value)
    {
        int index = hashFunc(key);

        Node *newNode =new Node;
        newNode->key=key;
        newNode->value= value;
        newNode->next =table[index];
        table[index] = newNode;
    }

    void display()
    {
        for (int i=0; i<10; i++)
        {
            cout << "Index " << i << ": ";
            Node *temp = table[i];
            while (temp != NULL)
            {
                cout << "(" << temp->key << ", "
                     << temp->value << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable myhash;
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");
    myhash.display();
}