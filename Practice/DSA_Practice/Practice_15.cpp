/*------------------------------------------------------------------------------------------+
| Reverse a doubly linked list.                                                             |
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
    Node *prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

class doublyLinkedList
{

    Node *head;

public:
    doublyLinkedList()
    {
        head = NULL;
    }

    // Insert at head
    void insertAtEnd(int x)
    {
        if (head == NULL)
        {
            head = new Node(x);
            return;
        }

        Node *temp = head;
        Node *newNode = new Node(x);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }

    // display the linked list
    void display()
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
        } while (temp != NULL);

        cout << "NULL" << endl;
    }

    // reverse linked list
    void reverse(){
        if(head == NULL){
            cout<<"Empty List"<<endl;
            return;
        }

        Node *temp = head;
        Node *prev = NULL;
        while(temp != NULL){
            prev = temp->prev;
            temp->prev = temp->next;
            temp->next = prev;
            temp = temp->prev;
        }
        head = prev->prev;
    
    }
};

int main()
{
    Node *head = NULL;
    doublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    dll.insertAtEnd(50);
    dll.display();
    dll.reverse();
    dll.display();
    return 0;
}