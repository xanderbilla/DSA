/*--------------------------------------------------------+
    Chapter: 6      | Queue
    Section: 6.2    | Queue using Linked List
+--------------------------------------------------------*/

#include <iostream>
#define ARRAY_LENGTH 5
using std::cout;
using std::endl;

class Queue
{
    int front;
    int rear;
    int arr[ARRAY_LENGTH];

public:
    Queue()
    {
        this->front = this->rear = -1;
    }

    void enQueue(int val);
    void deQueue();
    void display();
};

void Queue::enQueue(int val)
{
    if (rear == ARRAY_LENGTH - 1)
    {
        cout << "Queue is full" << endl;
    }

    if (front == -1)
    {
        front++;
    }

    rear++;
    arr[rear] = val;
}

void Queue::deQueue()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
    }

    if (front == rear)
    {
        front = rear = -1;
    }

    front++;
}

void Queue::display()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
    }

    int temp = front;
    while (temp <= rear)
    {
        cout << arr[temp++] << " ";
    }
    endl(cout);
}

int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.display();
    q.deQueue();
    q.display();
    q.deQueue();
    q.display();
}

/*--------------------------------------------------------
    Output:
        10 20 30
        20 30
        30

    Note:

+---------------------------------------------------------+
     Website: http://xanderbilla.com
     Email: dev.xanderbilla@gmail.com

     This program is written by © Xander Billa.
---------------------------------------------------------*/