/*Task#2: Suppose you have an AVL tree with the following elements: 50, 30, 70, 20, 40, 60, 80.
You need to insert a new node with value 55 into the tree and then display the tree after
performing a left rotation on the root. Write a C++ code to accomplish this task using the
AVLTree class and its methods.*/

#include <iostream>
using namespace std;

class Node
{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int v)
        {
            val = v;
            left = right = NULL;
        }
};

class AVLTree
{
    public:
        Node* root;
        AVLTree() { root = NULL; }

        Node* insert(Node* r, int k)
        {
            if (r == NULL)
                return new Node(k);
            if (k < r->val)
                r->left = insert(r->left, k);
            else if (k > r->val)
                r->right = insert(r->right, k);
            return r;
        }

        Node* leftrotate(Node* x)
        {
            Node* y = x->right;
            Node* temp = y->left;
            y->left = x;
            x->right = temp;
            return y;
        }

        void inorder(Node* r)
        {
            if (r == NULL)
                return;
            inorder(r->left);
            cout << r->val << " ";
            inorder(r->right);
        }
};

int main()
{
    AVLTree t;
    t.root = t.insert(t.root, 50);
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 70);
    t.root = t.insert(t.root, 20);
    t.root = t.insert(t.root, 40);
    t.root = t.insert(t.root, 60);
    t.root = t.insert(t.root, 80);
    t.root = t.insert(t.root, 55);
    cout << "Before rotation: ";
    t.inorder(t.root);
    t.root = t.leftrotate(t.root);
    cout << "After rotation: ";
    t.inorder(t.root);
}
