/*--------------------------------------------------------+
    Chapter: 3      | Linked List
    Section: 3.2    | Double Linked List
+--------------------------------------------------------*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList()
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
        head->prev = new_node;
        head = new_node;
    }

    void insertAtEnd(Node *&head, int val)
    {
        if (head == NULL)
        {
            insertAtHead(head, val);
            return;
        }

        Node *new_node = new Node(val);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }

    void insertAtPos(Node *&head, int val, int pos)
    {
        if (head == NULL)
        {
            insertAtHead(head, val);
            return;
        }
        Node *new_node = new Node(val);
        int count = 1;
        Node *temp = head;
        while (temp->next != NULL && count != pos-1)
        {
            temp = temp->next;
            count++;
        }
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }

    void updateAtPos(Node *&head, int val, int pos) {
        if(head == NULL) {
            return;
        }
        Node *temp = head;
        int count = 1;
        while(temp != NULL && count != pos) {
            temp = temp->next;
            count++;
        }
        temp->data = val;
    }

    void deleteAtHead(Node *&head) {
        if(head == NULL) {
            return;
        }
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }

    void deleteAtTail(Node *head) {
         if(head == NULL) {
            return;
        }
        Node *temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        temp->next = NULL;
        free(toDelete);
    }

    void deleteAtPos(Node *&head, int pos) {
        if(head == NULL) {
            return;
        }
        int count = 1;
        Node *temp = head;
        while(temp != NULL && count != pos-1) {
            temp = temp->next;
            count++;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        free(toDelete);
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
    Node *head = NULL;
    DoublyLinkedList dll;
    //insert at head
    dll.insertAtHead(head, 1);
    dll.insertAtHead(head, 2);
    dll.insertAtHead(head, 3);
    dll.insertAtHead(head, 4);
    dll.insertAtHead(head, 5);
    dll.display(head);

    // insert at end
    dll.insertAtEnd(head, 6);
    dll.display(head);

    // insert at pos
    dll.insertAtPos(head, 69, 3);
    dll.display(head);

    // update at pos
    dll.updateAtPos(head, 420, 3);
    dll.display(head);

    // delete at head
    dll.deleteAtHead(head);
    dll.display(head);

    // delete at tail
    dll.deleteAtTail(head);
    dll.display(head);

    // delete at pos
    dll.deleteAtPos(head, 3);
    dll.display(head);
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