/*--------------------------------------------------------+
    Chapter: 8      | Tree
    Section: 8.1    | Binary Search Tree
+--------------------------------------------------------*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
    private:
    Node *root;
    void insertNode(Node *&root, int val)
    {
        if (root == nullptr)
        {
            root = new Node(val);
            return;
        }
        if (val < root->data)
        {
            insertNode(root->left, val);
        }
        else
        {
            insertNode(root->right, val);
        }
    }

    void searchNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->data == key)
        {
            cout << "Found" << endl;
            return;
        }
        if (key < root->data)
        {
            searchNode(root->left, key);
        }
        else
        {
            searchNode(root->right, key);
        }
    }

    void preOrderTrav(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->data << " ";
        preOrderTrav(root->left);
        preOrderTrav(root->right);
    }

    void inOrderTrav(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrderTrav(root->left);
        cout << root->data << " ";
        inOrderTrav(root->right);
    }

public:
    void insertNode(int val)
    {
        insertNode(root, val);
    }

    void searchNode(int key)
    {
        searchNode(root, key);
    }

    void preOrderTrav()
    {
        preOrderTrav(root);
    }

    void deletePostOrderTrav(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        deletePostOrderTrav(root->left);
        deletePostOrderTrav(root->right);
        delete root;
    }

    ~BST()
    {
        deletePostOrderTrav(root);
    }
};

/*
        Hey Riya,
        If you don't mind sending your full
        picture in that traditional?

        You loook so beautiful in that saree ;)

        ---------------RECIEVED---------------

        Thank you for that beautiful picture

        But I wanted to see head to toe...
*/

int main()
{
    BST bst;
    bst.insertNode(10);
    bst.insertNode(20);
    bst.insertNode(30);
    bst.insertNode(40);
    bst.insertNode(50);
    bst.preOrderTrav();
    cout << endl;
    return 0;
}

/*--------------------------------------------------------
    Output:


    Note:

+---------------------------------------------------------+
     Website: http://xanderbilla.com
     Email: dev.xanderbilla@gmail.com

     This program is written by © Xander Billa.
---------------------------------------------------------*/