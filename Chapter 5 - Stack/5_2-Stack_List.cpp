/*--------------------------------------------------------+
    Chapter: 5      | Stack
    Section: 5.2    | Stack using Linked List
+--------------------------------------------------------*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    // Check if stack underflow
    bool isEmpty()
    {
        return (top == NULL);
    }

    // push operation (insertion at head)
    void push(int val)
    {
        if (isEmpty())
        {
            top = new Node(val);
            return;
        }
        Node *new_node = new Node(val);
        new_node->next = top;
        top = new_node;
    }

    // pop operation (deletion at head)
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    // peek operation (return head element)
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return top->data;
    }

    // display operation
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return;
        }
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();

    //
    s.pop();
    s.display();

    cout << s.peek() << endl;

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