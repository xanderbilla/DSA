/*--------------------------------------------------------+
    Chapter: 6      | Queue
    Section: 6.2    | Queue using Linked List
+--------------------------------------------------------*/

#include <iostream>

using std::cout;
using std::endl;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue
{
    Node *front, *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void insertQueue(int val);
    void deleteQueue();
    void display();
    void peek();
    ~Queue();
};

void Queue::insertQueue(int val)
{
    Node *newNode = new Node(val);

    if (front == NULL)
    {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void Queue::deleteQueue()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    front = front->next;
    delete temp;
}

void Queue::display()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void Queue::peek()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << front->data << endl;
}

Queue::~Queue()
{
    Node *temp = front;
    while (temp != NULL)
    {
        front = front->next;
        delete temp;
        temp = front;
    }
}


int main()
{
    Queue q;
    // insertion
    q.insertQueue(10);
    q.insertQueue(20);
    q.insertQueue(30);
    q.display();

    // deletion
    q.deleteQueue();
    q.display();

    // peek
    q.peek();
    return 0;
}

/*--------------------------------------------------------
    Output:
    10->20->30->NULL
    20->30->NULL
    30

    Note:

+---------------------------------------------------------+
     Website: http://xanderbilla.com
     Email: dev.xanderbilla@gmail.com

     This program is written by © Xander Billa.
---------------------------------------------------------*/