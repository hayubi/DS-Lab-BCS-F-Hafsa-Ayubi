/*Question 1: Implement a binary search tree and perform all operations you learned above like:
Inserting, Deleting, Searching, and Traversing.*/

#include <iostream>
#include <queue>
using namespace std;

class Node 
{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int value) 
        {
            data = value;
            left = right = NULL;
        }
};

class Tree 
{
    public:
        Node* root;
        Tree() { root = NULL; }

        Node* insert(Node* root, int value) 
        {
            if (root == NULL)
                return new Node(value);

            if (value < root->data)
                root->left = insert(root->left, value);
            else if (value > root->data)
                root->right = insert(root->right, value);
            return root;
        }

        bool search(Node* root, int key) 
        {
            if (root == NULL)
                return false;
            if (root->data == key)
                return true;
            else if (key < root->data)
                return search(root->left, key);
            else
                return search(root->right, key);
        }

        Node* findMin(Node* root) 
        {
            while (root->left != NULL)
                root = root->left;
            return root;
        }

        Node* deleteNode(Node* root, int key) 
        {
            if (root == NULL)
                return root;

            if (key < root->data)
                root->left = deleteNode(root->left, key);
            else if (key > root->data)
                root->right = deleteNode(root->right, key);
            else 
            {
                if (root->left == NULL && root->right == NULL) 
                {
                    delete root;
                    return NULL;
                }
                else if (root->left == NULL) 
                {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == NULL) 
                {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }
                else 
                {
                    Node* temp = findMin(root->right);
                    root->data = temp->data;
                    root->right = deleteNode(root->right, temp->data);
                }
            }
            return root;
        }

        void inorder(Node* root) 
        {
            if (root == NULL) 
                return;
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }

        void preorder(Node* root) 
        {
            if (root == NULL) 
                return;
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }

        void postorder(Node* root) 
        {
            if (root == NULL) 
                return;
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }

        void levelOrder(Node* root)
        {
            if (root == NULL)
                return;
            queue<Node*> q;
            q.push(root);
            while (!q.empty())
            {
                Node* current = q.front();
                q.pop();
                cout << current->data << " ";
                if (current->left != NULL)
                    q.push(current->left);
                if (current->right != NULL)
                    q.push(current->right);
            }
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
    t.inorder(t.root);
    cout << endl;
    if (t.search(t.root, 40))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    t.root = t.deleteNode(t.root, 70);
    t.inorder(t.root);
    cout << endl;
    t.levelOrder(t.root);
    cout << endl;
}
