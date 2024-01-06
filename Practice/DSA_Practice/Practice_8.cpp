/*------------------------------------------------------------------------------------------+
| Singly Linked List Implementation                                                         |
+-------------------------------------------------------------------------------------------+
|Author: Vikas Singh                                                                        |
|Date of Publication: 1/1/2024                                                              |
|Copyright © 2023 Xander Billa                                                              |
+------------------------------------------------------------------------------------------*/

#include <iostream>
#define MAX_SIZE 100
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}

    static void insertAtHead(Node *&head, int val);
    static void insertAtEnd(Node *&head, int val);
    static void insertAtPosNode(Node *&head, int val, int pos);
    static void deleteAtHead(Node *&head);
    static void deleteAtEnd(Node *&head);
    static void deleteAtPosNode(Node *&head, int pos);
    static void display(Node *head);
};

void Node::insertAtHead(Node *&head, int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void Node::insertAtEnd(Node *&head, int val) {
    if (head == nullptr) {
        insertAtHead(head, val);
        return;
    }

    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Node::insertAtPosNode(Node *&head, int val, int pos) {
    if (head == nullptr || pos <= 1) {
        insertAtHead(head, val);
        return;
    }

    Node *newNode = new Node(val);
    Node *temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != nullptr) {
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void Node::deleteAtHead(Node *&head) {
    if (head == nullptr) {
        cout << "Empty List" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

void Node::deleteAtEnd(Node *&head) {
    if (head == nullptr) {
        cout << "Empty List" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void Node::deleteAtPosNode(Node *&head, int pos) {
    if (head == nullptr || pos <= 1) {
        deleteAtHead(head);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < pos - 1 && temp != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position" << endl;
        return;
    }

    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void Node::display(Node *head) {
    if (head == nullptr) {
        cout << "Empty List" << endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node *head = nullptr; // Initially the list is empty

    Node::insertAtHead(head, 10);
    Node::insertAtHead(head, 20);
    Node::insertAtHead(head, 30);
    Node::insertAtHead(head, 40);
    Node::insertAtHead(head, 50);
    Node::insertAtEnd(head, 60);        // Insert 60 at the end of the list
    Node::insertAtPosNode(head, 70, 3); // Insert 70 at the 3rd position of the list
    Node::display(head);

    Node::deleteAtHead(head); // Delete the head node of the list
    Node::display(head);

    Node::deleteAtEnd(head); // Delete the last node of the list
    Node::display(head);

    Node::deleteAtPosNode(head, 3); // Delete the 3rd node of the list
    Node::display(head);

    return 0;
}
