/*--------------------------------------------------------+
    Chapter: 5      | Stack
    Section: 5.1    | Stack using Array
+--------------------------------------------------------*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Stack
{
    int top;
    int size;
    int *arr;

    Stack(int n)
    {
        top = -1;
        size = n;
        arr = new int[size];
    }
};

class StackOperations
{
    Stack *s;

public:
    StackOperations(int n)
    {
        s = new Stack(n);
    }

    // Check if stack is full
    bool isFull()
    {
        return (s->top == s->size - 1);
    }

    // Push
    void push(int val){
        if(isFull()){
            cout << "Stack is full" << endl;
            return;
        }

        s->top++;
        s->arr[s->top] = val;
    }

    // Pop
    void pop(){
        if(s->top == -1){
            cout << "Stack is empty" << endl;
            return;
        }

        s->top--;
    }

    // Peek
    int peek(){
        if(s->top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }

        return s->arr[s->top];
    }

    // Display
    void display(){
        if(s->top == -1){
            cout << "Stack is empty" << endl;
            return;
        }

        for(int i = s->top; i >= 0; i--){
            cout << s->arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    StackOperations s(5);
    if (s.isFull())
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Stack is Empty" << endl;
    }

    //Stack insertions
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //Stack display
    s.display();

    //Stack peek
    cout << "Peek: " << s.peek() << endl;

    //Stack pop
    s.pop();
    s.push(50);
    s.display();
    return 0;
}

/*--------------------------------------------------------
    Output:
        Stack is Empty
        40 30 20 10 
        Peek: 40
        50 30 20 10

    Note:

+---------------------------------------------------------+
     Website: http://xanderbilla.com
     Email: dev.xanderbilla@gmail.com

     This program is written by © Xander Billa.
---------------------------------------------------------*/