/*------------------------------------------------------------------------------------------+
| Doubly Linked List Implementation                                                         |
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
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}

    void insertAtHead(int val);
    void insertAtEnd(int val);
    void insertAtPosNode(int val, int pos);
    void deleteAtHead();
    void deleteAtEnd();
    void deleteAtPosNode(int pos);
    void display();
};

Node *head = nullptr;

void Node::insertAtHead(int val) {
    Node *newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void Node::insertAtEnd(int val) {
    Node *newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void Node::insertAtPosNode(int val, int pos) {
    if (pos <= 0) {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1 || head == nullptr) {
        insertAtHead(val);
        return;
    }

    Node *newNode = new Node(val);
    Node *temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp->next == nullptr && count != pos - 1) {
        cout << "Invalid position" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void Node::deleteAtHead() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void Node::deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

void Node::deleteAtPosNode(int pos) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    if (pos <= 0) {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1) {
        deleteAtHead();
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < pos && temp != nullptr) {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) {
        cout << "Invalid position" << endl;
        return;
    }

    if (temp->next == nullptr) {
        temp->prev->next = nullptr;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void Node::display() {
    Node *temp = head;
    if (temp == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node list(0); // Create an instance of the Node class

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.insertAtHead(40);
    list.insertAtHead(50);
    list.insertAtEnd(60);        // Insert 60 at the end of the list
    list.insertAtPosNode(70, 3); // Insert 70 at the 3rd position of the list
    list.display();

    list.deleteAtHead(); // Delete the head node of the list
    list.display();

    list.deleteAtEnd(); // Delete the last node of the list
    list.display();

    list.deleteAtPosNode(3); // Delete the 3rd node of the list
    list.display();

    return 0;
}
