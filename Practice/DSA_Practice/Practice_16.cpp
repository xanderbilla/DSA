/*------------------------------------------------------------------------------------------+
| Delete a given key from linked list                                                       |
+-------------------------------------------------------------------------------------------+
|Author: Vikas Singh                                                                        |
|Date of Publication: 6/1/2024                                                              |
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
    void insertAtEnd(int x)
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

    // delete a given key from linked list
    void deleteKey(int key){
        if(head ==  NULL){
            cout<<"Empty List"<<endl;
            return;
        }

        Node *temp = head;
        while(temp->next->data != key){
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
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
        } while (temp != head);

        cout << "NULL" << endl;
    }
};

int main()
{
    Node *head = NULL;
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.insertAtEnd(50);
    ll.display();
    ll.deleteKey(50);
    ll.display();
    return 0;
}