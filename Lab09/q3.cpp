/*Task#3: Suppose you have an AVL tree with the following nodes: 10, 5, 15, 3, and 7 (in this
order). Perform the following steps:
1. Insert the value 12 into the tree.
2. Calculate the balance factor for each node.
3. Check the height of the tree.
4. If the tree becomes unbalanced during insertion, implement the rotations required to
5. maintain balance.
6. Provide the final balanced AVL tree.*/

#include <iostream>
using namespace std;

class Node 
{
    public:
        int key;
        int height;
        Node* left;
        Node* right;
        Node(int k) 
        {
            key = k;
            height = 1;
            left = right = NULL;
        }
};

int getHeight(Node* n) 
{
    if (n == NULL) 
        return 0;
    return n->height;
}

int getBalance(Node* n) 
{
    if (n == NULL) 
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

int maxH(int a, int b) { return (a>b) ? a : b; }

Node* rightRotate(Node* y) 
{
    Node* x = y->left;
    Node* T = x->right;
    x->right = y;
    y->left = T;
    y->height = maxH(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxH(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) 
{
    Node* y = x->right;
    Node* T = y->left;
    y->left = x;
    x->right = T;
    x->height = maxH(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxH(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node* insert(Node* root, int key) 
{
    if (root == NULL)
        return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    root->height = maxH(getHeight(root->left), getHeight(root->right)) + 1;

    int bal = getBalance(root);
    if (bal>1 && key < root->left->key) // LL
        return rightRotate(root);
    if (bal<-1 && key > root->right->key) // RR
        return leftRotate(root);

    if (bal>1 && key > root->left->key) // LR
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bal<-1 && key < root->right->key) // RL
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(Node* r) 
{
    if (r == NULL) 
        return;
    inorder(r->left);
    cout << r->key << " ";
    inorder(r->right);
}

int main() 
{
    Node* root = NULL;
    int arr[] = {10,5,15,3,7};
    for (int i=0; i<5; i++)
        root = insert(root, arr[i]);

    root = insert(root, 12);
    cout << "Final Balanced AVL Tree (Inorder): ";
    inorder(root);
    cout << endl;
    cout << "Height: " << getHeight(root) << endl;
    cout << "Balance factors:" << endl;
    cout << "Root: " << getBalance(root) << endl;
}