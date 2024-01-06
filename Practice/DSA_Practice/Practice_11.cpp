/*------------------------------------------------------------------------------------------+
| Write a function that counts the number of times a given int occurs in a Linked List.     |
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

    // element count in linked list
    void find(Node *head, int key){
        if(head == NULL){
            cout << "Empty List" << endl;
            return;
        }

        Node *temp = head;
        int count = 0;
        while(temp != NULL){
            if(temp->data == key){
                count++;
                temp = temp->next;
            }
            else{
                temp = temp->next;
            }
        }
        cout << "Count of " << key << " is: " << count << endl;
        return;
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
    ll.insertAtEnd(head, 20);
    ll.insertAtEnd(head, 30);
    ll.insertAtEnd(head, 40);
    ll.insertAtEnd(head, 50);
    ll.insertAtEnd(head, 20);
    ll.insertAtEnd(head, 60);
    ll.insertAtEnd(head, 20);
    ll.display(head);
    ll.find(head, 20);
    return 0;
}