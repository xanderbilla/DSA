/*------------------------------------------------------------------------------------------+
| Write a function that count number of nodes in a circular linked list.                    |
+-------------------------------------------------------------------------------------------+
|Author: Vikas Singh                                                                        |
|Date of Publication: 1/1/2024                                                              |
|Copyright © 2023 Xander Billa                                                              |
+------------------------------------------------------------------------------------------*/

#include <iostream>
#define MAX_SIZE 100
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

class LinkedList
{

    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Insert at head
    void insertAtEnd(Node *&head, int x)
    {
        if (head == NULL)
        {
            head = new Node(x);
            head->next = head;
            return;
        }

        Node *temp = head;
        Node *newNode = new Node(x);
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        return;
    }

    // element count in linked list
    void count(Node *head)
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }

        Node *temp = head;
        int count = 0;
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }
        cout << "Number of elements in circular linked list are: " << count+1 << endl;
        return;
    }

    // display the linked list
    void display(Node *head)
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);

        cout << "NULL" << endl;
    }
};

int main()
{
    Node *head = NULL;
    LinkedList ll;
    ll.insertAtEnd(head, 10);
    ll.insertAtEnd(head, 20);
    ll.insertAtEnd(head, 30);
    ll.insertAtEnd(head, 40);
    ll.insertAtEnd(head, 50);
    ll.display(head);
    ll.count(head);
    return 0;
}