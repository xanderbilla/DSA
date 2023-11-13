/*--------------------------------------------------------+
    Chapter: 3      | Linked List
    Section: 3.1    | Singly Linked List
+--------------------------------------------------------*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertAtHead(Node *&head, int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            return;
        }
        Node *new_node = new Node(val);
        new_node->next = head;
        head = new_node;
    }

    void insertAtEnd(Node *&head, int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }

    void insertAtPos(Node *&head, int pos, int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            return;
        }
        if (pos == 0)
        {
            insertAtHead(head, val);
            return;
        }
        Node *temp = head;
        int count = 0;
        while (temp != NULL && count != pos - 1)
        {
            temp = temp->next;
            count++;
        }
        Node *new_node = new Node(val);
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void updateAtPos(Node *&head, int pos, int val)
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        int count = 0;
        while (temp != NULL && count != pos)
        {
            temp = temp->next;
            count++;
        }
        temp->data = val;
    }

    bool searchNode(Node *head, int key)
    {
        if (head == NULL)
        {
            return false;
        }
        Node *temp = NULL;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Found" << endl;
                return true;
            }
            temp = temp->next;
        }
    }

    void display(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList l;
    Node *head = NULL;
    l.insertAtHead(head, 1);
    l.insertAtHead(head, 2);
    l.insertAtHead(head, 3);
    l.display(head);
    l.insertAtEnd(head, 4);
    l.insertAtEnd(head, 5);
    l.display(head);
    l.insertAtPos(head, 2, 6);
    l.updateAtPos(head, 2, 7);
    l.display(head);
    l.searchNode(head, 7);
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