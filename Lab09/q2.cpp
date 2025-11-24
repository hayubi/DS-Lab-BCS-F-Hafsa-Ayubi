/*Task#4: Find the kth smallest and largest value in the AVL tree and print its key also print both
the left side and right side height of the tree starting from root.*/

#include <iostream>
using namespace std;

class Node
{
    public:
        int key;
        Node* left;
        Node* right;
        Node(int k)
        {
            key = k;
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
            if (k < r->key)
                r->left = insert(r->left, k);
            else if (k > r->key)
                r->right = insert(r->right, k);
            return r;
        }

        int height(Node* r)
        {
            if (r == NULL)
                return 0;
            int lh = height(r->left);
            int rh = height(r->right);
            return max(lh, rh) + 1;
        }

        // kth smallest
        int kthSmallest(Node* r, int &count, int k)
        {
            if (r == NULL)
                return -1;
            int leftAns = kthSmallest(r->left, count, k);
            if (leftAns != -1)
                return leftAns;

            count++;
            if (count == k)
                return r->key;
            return kthSmallest(r->right, count, k);
        }

        // kth largest
        int kthLargest(Node* r, int &count, int k)
        {
            if (r == NULL)
                return -1;
            int rightAns = kthLargest(r->right, count, k);
            if (rightAns != -1)
                return rightAns;

            count++;
            if (count == k)
                return r->key;
            return kthLargest(r->left, count, k);
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

    int k;
    cout << "Enter k: ";
    cin >> k;
    int c1 = 0, c2 = 0;
    int kthSmall = t.kthSmallest(t.root, c1, k);
    int kthLarge = t.kthLargest(t.root, c2, k);
    cout << "Kth smallest = " << kthSmall << endl;
    cout << "Kth largest  = " << kthLarge << endl;
    int leftHeight = t.height(t.root->left);
    int rightHeight = t.height(t.root->right);
    cout << "Left subtree height  = " << leftHeight << endl;
    cout << "Right subtree height = " << rightHeight << endl;
}