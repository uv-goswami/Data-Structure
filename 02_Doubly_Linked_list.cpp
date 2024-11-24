#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insertAtHead(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

Node* traverse(int n) {
    Node* temp = head;
    for (int i = 1; i < n && temp != nullptr; i++) {
        temp = temp->next;
    }
    return temp;
}

void insertInBetween(int value, int i) {
    Node* temp = traverse(i-1);
    if (i <= 0) {
        cout << "Invalid Position" << endl;
    } else if (temp == nullptr) {
        cout << "Position out of bound" << endl;
    } else if (i == 1) {
        insertAtHead(value);
    } else {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

void deleteHead() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void deleteEnd() {
    if (head == nullptr) return;
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void deleteInBetween(int i) {
    if (i < 1) {
        cout << "Invalid Position" << endl;
        return;
    }
    if (i == 1) {
        deleteHead();
        return;
    }
    Node* temp = traverse(i-1);
    Node* temp2 = traverse(i);
    if (temp == nullptr || temp2 == nullptr) {
        cout << "Invalid Position" << endl;
        return;
    }
    if (temp2->next == nullptr) {
        temp->next = nullptr;
    } else {
        temp->next = temp2->next;
        temp2->next->prev = temp;
    }
    delete temp2;
}

Node* search(int n){
  Node* temp = head;

  while( temp != nullptr){
    if(temp->data == n){
      cout << "Pointer Of '" << n << "' is " << temp <<endl;
      return temp;
    }
    else{
    temp = temp->next;
    }
  }
}

void reverse(){
  Node *temp = nullptr;
  Node* current = head;

  while(current != nullptr){
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }

  if(temp !=nullptr){
    head = temp->prev;
  }
}

void defaultList(){
  head = NULL;
  insertAtHead(5);
  insertAtHead(4);
  insertAtHead(3);
  insertAtHead(2);
  insertAtHead(1);
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void choice(){
  int n;
    cout<< "Chose on of the Following Option" << endl;
    cout<< "1. Insert at Head" << endl;
    cout<< "2. Insert at ith position" <<endl;
    cout<< "3. Delete at Head" << endl;
    cout<< "4. Delete at ith position" <<endl;
    cout<< "5. Search for an element x in the singly linked list and return its pointer" << endl;
    cout<< "6. Reverse the Linked List" <<endl;
    cin>> n;

    if (n == 1){
      int x;
      cout << "Enter the element you want to insert at Head"<< endl;
      cin >> x;
      insertAtHead(x);
    }
    if (n == 2){
      int x, i;
      cout << "Enter the element you want to insert"<< endl;
      cin >> x;
      cout << "Enter the Position"<< endl;
      cin >> i;
      insertInBetween(x,i);
    }
    if (n == 3){
      deleteHead();
      cout << "Element at head deleted"<< endl;
    }
    if (n == 4){
      int i;
      cout << "Enter the Position you want to delete"<< endl;
      cin >> i;

      deleteInBetween(i);
    }
    if (n == 5){
      int x;
      cout << "Enter the element you want to search"<< endl;
      cin >> x;

      search(x);

    }

    if (n == 6){
      reverse();
    }

    else if(n>6 || n<1){
      cout << "Invalid Option" << endl;
    }
}


int main(){
  cout << "**********************************************************************************" << endl;
  defaultList();
  cout << "**********************************************************************************" << endl;

  choice();
  cout<< "Doubly linked list:  ";
  display();
  cout << endl;

  return 0;
}
