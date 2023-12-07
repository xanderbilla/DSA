/*--------------------------------------------------------+
    Chapter: 6      | Queue
    Section: 6.2    | Queue using Linked List
+--------------------------------------------------------*/

#include <iostream>

using std::cout;
using std::endl;

class Queue
{
    int front;
    int rear;
    int size;
    int *arr;

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }

    void enQueue(int val);
    void deQueue();
    void display();
    
    ~Queue()
    {
        delete[] arr;
    }
};

void Queue::enQueue(int val)
{
    if (rear == size - 1)
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

    for (int i = front; i <= rear; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q(5);
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