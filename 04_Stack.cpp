#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
public:
    Node* head = nullptr;

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        Display();
    }

    void pop() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;
        
        Display();
    }

    void top() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
        } else {
            cout << head->data << endl;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout<< "*****************" << endl;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.pop();
    stack.top();

    return 0;
}
