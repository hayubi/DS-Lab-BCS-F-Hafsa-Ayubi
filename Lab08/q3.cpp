/*Question#4: Search for the value defined by the user in the tree. If the value does not
exist insert it and print the new tree.*/

#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int v)
        {
            data = v;
            left = right = NULL;
        }
};

class Tree
{
    public:
        Node* root;
        Tree() { root = NULL; }

        Node* insert(Node* r, int v)
        {
            if (r == NULL)
                return new Node(v);
            if (v < r->data)
                r->left = insert(r->left, v);
            else if (v > r->data)
                r->right = insert(r->right, v);
            return r;
        }

        bool search(Node* r, int key)
        {
            if (r == NULL)
                return false;
            if (r->data == key)
                return true;
            else if (key < r->data)
                return search(r->left, key);
            else
                return search(r->right, key);
        }

        void inorder(Node* r)
        {
            if (r == NULL)
                return;
            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }
};

int main()
{
    Tree t;
    t.root = t.insert(t.root, 50);
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 70);
    t.root = t.insert(t.root, 20);
    t.root = t.insert(t.root, 40);
    t.root = t.insert(t.root, 60);
    t.root = t.insert(t.root, 80);

    int x;
    cout << "Enter value to search: ";
    cin >> x;
    if (t.search(t.root, x))
        cout << "Value exists" << endl;
    else
    {
        cout << "Value doesnot exist" << endl;
        t.root = t.insert(t.root, x);
        cout << "New tree: ";
        t.inorder(t.root);
        cout << endl;
    }
}