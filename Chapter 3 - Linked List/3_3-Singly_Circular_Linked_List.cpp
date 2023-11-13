/*--------------------------------------------------------+
    Chapter: 3      | Linked List
    Section: 3.3    | Singly Circular Linked List
+--------------------------------------------------------*/

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct Node{
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class CircularLinkedList{
    Node *head;
    public:
    CircularLinkedList(){
        head = NULL;
    }

    void insertAtHead(Node *&head, int val){
        if(head == NULL){
            head = new Node(val);
            head->next = head;
            return;
        }

        Node *new_node = new Node(val);
        Node *temp = head;
        new_node->next = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display(Node *head){
        if(head == NULL){
            return;
        }

        Node *temp = head;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);
        cout << endl;
    }
};

int main(){
    Node *head = NULL;
    CircularLinkedList cll;
    cll.insertAtHead(head, 10);
    cll.insertAtHead(head, 20);
    cll.insertAtHead(head, 30);
    cll.insertAtHead(head, 40);
    cll.display(head);
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