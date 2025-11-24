/*Question#2: Reuse the methods from above question 1 and complete below question:
You are required to implement a game titled “BattleQuest: BST Arena” using a Binary
Search Tree (BST) where each node in the tree stores a Combatant object. This
game simulates a classic RPG-style battle between a player’s team of heroes and a
team of enemies. The core challenge involves managing two separate BSTs — one for
the player’s team and another for the enemy team — where each node contains a
Combatant object with attributes such as name, health points (HP), and attack power.
The game follows a strict turn-based combat system, where the player’s team and the
enemy team alternate turns. Only the frontline combatant — defined as the node with
the smallest key value (i.e., the leftmost node in the BST) participates in combat during
each turn.
When a combatant’s health drops to zero or below, that combatant is removed from
their respective BST. The next available combatant in the tree (the new leftmost node)
becomes the frontline fighter for the following turn.
The battle continues until one team’s BST becomes empty, determining the winner.
The player’s team should be initialized with five heroes. The enemy team should be
initialized with five enemies.
Both trees should be constructed using insertions according to the BST property based
on the combatant’s name or unique ID.
The player always attacks first in each round, followed by the enemy counterattack.
During an attack: The attacker’s damage = base attack power + random value (0 to 4)
The damage will affect the defender’s health. If the defender’s health ≤ 0, they are
removed from their BST immediately. The next combatant automatically takes their
place as the new frontline fighter.

During each turn, the game must display the following information clearly:
 Round number
 Names and current HP of all heroes and enemies (in BST order)
 Active attackers and defenders
 Damage dealt in the attack
 Updated HP values after each hit
 Elimination messages when a combatant is defeated
 Victory message when one BST becomes empty*/

#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant
{
    public:
        string name;
        int hp;
        int attack;
        Combatant() {}
        Combatant(string n, int h, int a)
        {
            name = n;
            hp = h;
            attack = a;
        }
};

class Node 
{
    public:
        Combatant fighter;
        Node* left;
        Node* right;
        Node(Combatant value) 
        {
            fighter = value;
            left = right = NULL;
        }
};

class Tree 
{
    public:
        Node* root;
        Tree() { root = NULL; }

        Node* insert(Node* root, Combatant c) 
        {
            if (root == NULL)
                return new Node(c);
            if (c.name < root->fighter.name)
                root->left = insert(root->left, c);
            else if (c.name > root->fighter.name)
                root->right = insert(root->right, c);
            return root;
        }

        Node* findMin(Node* root) 
        {
            while (root->left != NULL)
                root = root->left;
            return root;
        }

        Node* deleteNode(Node* root, string key) 
        {
            if (root == NULL)
                return root;
            if (key < root->fighter.name)
                root->left = deleteNode(root->left, key);
            else if (key > root->fighter.name)
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
                    root->fighter = temp->fighter;
                    root->right = deleteNode(root->right, temp->fighter.name);
                }
            }
            return root;
        }

        void inorder(Node* root) 
        {
            if (root == NULL) 
                return;
            inorder(root->left);
            cout << root->fighter.name << "(" << root->fighter.hp << ") ";
            inorder(root->right);
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
                cout << current->fighter.name << "(" << current->fighter.hp << ") ";
                if (current->left != NULL)
                    q.push(current->left);
                if (current->right != NULL)
                    q.push(current->right);
            }
        }

        Node* frontline(Node* root)
        {
            if (root == NULL)
                return NULL;
            while (root->left != NULL)
                root = root->left;
            return root;
        }

        bool isEmpty()
        {
            if (root == NULL)
                return true;
            else
                return false;
        }
};

void displayTeams(Tree &p, Tree &e)
{
    cout << endl << "Player Team: ";
    p.inorder(p.root);
    cout << endl << "Enemy Team : ";
    e.inorder(e.root);
    cout << endl;
}

int main() 
{
    srand(time(0));
    Tree p;
    Tree e;
    p.root = p.insert(p.root, Combatant("Aiden", 30, 6));
    p.root = p.insert(p.root, Combatant("Blaze", 28, 7));
    p.root = p.insert(p.root, Combatant("Cyra", 26, 5));
    p.root = p.insert(p.root, Combatant("Darius", 35, 4));
    p.root = p.insert(p.root, Combatant("Elara", 22, 8));
    e.root = e.insert(e.root, Combatant("Orc", 25, 5));
    e.root = e.insert(e.root, Combatant("Shade", 27, 4));
    e.root = e.insert(e.root, Combatant("Ghoul", 22, 6));
    e.root = e.insert(e.root, Combatant("Viper", 30, 5));
    e.root = e.insert(e.root, Combatant("Reaper", 35, 7));

    int round = 1;
    while (!p.isEmpty() && !e.isEmpty())
    {
        cout << "Round " << round << ": ";
        displayTeams(p, e);
        Node* pa = p.frontline(p.root);
        Node* ea = e.frontline(e.root);
        cout << "\nPlayer Attacker: " << pa->fighter.name  << " (HP=" << pa->fighter.hp << ")";
        cout << "\nEnemy Defender : " << ea->fighter.name  << " (HP=" << ea->fighter.hp << ")\n";
        int damage = pa->fighter.attack + (rand() % 5);
        cout << pa->fighter.name << " attacks " << ea->fighter.name  << " for " << damage << " damage\n";

        ea->fighter.hp -= damage;
        if (ea->fighter.hp <= 0)
        {
            cout << ea->fighter.name << " has been defeated\n";
            e.root = e.deleteNode(e.root, ea->fighter.name);
        }
        if (e.isEmpty())
        {
            cout << "\nAll enemies defeated! Player won\n";
            break;
        }


        pa = p.frontline(p.root);
        ea = e.frontline(e.root);
        cout << "\nEnemy Attacker: " << ea->fighter.name  << " (HP=" << ea->fighter.hp << ")";
        cout << "\nPlayer Defender: " << pa->fighter.name  << " (HP=" << pa->fighter.hp << ")\n";
        damage = ea->fighter.attack + (rand() % 5);
        cout << ea->fighter.name << " attacks " << pa->fighter.name  << " for " << damage << " damage\n";

        pa->fighter.hp -= damage;
        if (pa->fighter.hp <= 0)
        {
            cout << pa->fighter.name << " has fallen\n";
            p.root = p.deleteNode(p.root, pa->fighter.name);
        }
        if (p.isEmpty())
        {
            cout << "\nAll heroes defeated! Enemy won\n";
            break;
        }
        round++;
    }
}