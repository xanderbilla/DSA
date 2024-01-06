/*------------------------------------------------------------------------------------------+
| Print the middle of a given linked list                                                   |
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
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(x);
        return;
    }

    // List size
    int size(Node *head)
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
        }

        Node *temp = head;
        int size = 0;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }

    // Middle of the list
    void middle(Node *head, int size)
    {
        int middle = size / 2;
        Node *temp = head;
        int count = 0;
        if (middle % 2 == 0)
        {
            while (count < middle)
            {
                temp = temp->next;
                count++;
            }
        }
        else
        {
            while (count < middle - 1)
            {
                temp = temp->next;
                count++;
            }
        }
        cout << "Middle element is: " << temp->data << endl;
    }

    // display the linked list
    void
    display(Node *head)
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }

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
    Node *head = NULL;
    LinkedList ll;
    ll.insertAtEnd(head, 10);
    ll.insertAtEnd(head, 20);
    ll.insertAtEnd(head, 30);
    ll.insertAtEnd(head, 40);
    ll.insertAtEnd(head, 50);
    ll.insertAtEnd(head, 60);
    ll.display(head);
    if (ll.size(head) > 0)
    {
        ll.middle(head, ll.size(head));
    }
    return 0;
}