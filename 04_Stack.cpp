#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
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
    }

    void pop() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return head->data;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void display() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int evaluatePostfix(const string& expression) {
    Stack stack;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(stoi(token));
        } else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            switch (token[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }
    return stack.top();
}

int evaluatePrefix(const string& expression) {
    Stack stack;
    istringstream iss(expression);
    vector<string> tokens;
    string token;

    while (iss >> token) {
        tokens.push_back(token);
    }
    reverse(tokens.begin(), tokens.end());

    for (const auto& tok : tokens) {
        if (isdigit(tok[0])) {
            stack.push(stoi(tok));
        } else {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();

            switch (tok[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }
    return stack.top();
}

int main() {
    string postfix = "5 6 + 4 *";
    string prefix = "* + 5 6 4";

    cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;
    cout << "Prefix Evaluation: " << evaluatePrefix(prefix) << endl;

    return 0;
}
