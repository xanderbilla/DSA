#include<iostream>

using std::cout; 
using std::endl;

struct Node
{
    int data;
    int priority;
    Node *next;

    Node(int val, int priority) : data(val), priority(priority), next(nullptr) {}
};

Node *temp, *front, *rear;

void inQueue(int val, int priority){
    if(front == nullptr && rear == nullptr){
        front = rear = new Node(val, priority);
        return;
    }

    if(priority > front->priority){
        Node *newNode = new Node(val, priority);
        newNode->next = front;
        front = newNode;
        return;
    }

    temp = front;
    while(priority <= temp->priority && temp->next != nullptr){
        temp = temp->next;
    }
    Node *newNode = new Node(val, priority);
    newNode->next = temp->next;
    temp->next = newNode;
}

void dequeue(){
    if(front == nullptr){
        cout << "Queue is empty" << endl;
        return;
    }

    if(front == rear){
        front = rear = nullptr;
        return;
    }

    Node *temp = front;
    front = front->next;
    delete temp;
}

void display(){
    if(front == nullptr){
        cout << "Queue is empty" << endl;
        return;
    }

    temp = front;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    inQueue(10, 1);
    inQueue(20, 2);
    inQueue(30, 3);
    inQueue(50, 5);
    inQueue(60, 6);
    inQueue(70, 7);
    inQueue(80, 8);
    inQueue(90, 9);
    inQueue(100, 10);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
}