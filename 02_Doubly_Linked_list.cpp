#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;
};

Node* head;

void insertAtHead(int value){
  Node* newNode = new Node();
  newNode -> data = value;
  newNode -> next = head;
  newNode -> prev = nullptr;
  head = newNode;
}

Node* traverse(int n){
  Node* temp = head;
  
  for(int i = 1 ; i < n && temp != nullptr; i++){
    temp = temp->next;
  }
  return temp;
}

void insertInBetween(int value, int i){
  Node* temp = traverse(i-1);
  if(i<=0){
    cout << "Invalid Position" << endl;
  }

  else if(temp == nullptr){
    cout <<"Position out of bound"<< endl;
  }

  else if(i == 1){
    insertAtHead(value);
  }

  else {
    Node* newNode = new Node();
    newNode -> data = value;
    newNode -> next = temp -> next;
    newNode -> prev = temp->prev;
    temp -> next = newNode;
  }
}

void deleteHead(){
  Node* temp = head;
  head = head->next;
  delete temp;
}

void deleteInBetween(int i){
  Node* temp = traverse(i);
  if(i == 1){
    deleteHead();
    return;
  }

  else if(head == nullptr){
    cout << "Linked List is empty" << endl;
    return;
  }

  else{
  if(temp == nullptr){
    cout << "Position " << i << " does not exist" << endl;
    return;
  }

  if(temp->prev != nullptr){
    temp->prev->next = temp->next;
  }

  if(temp->next != nullptr){
    temp->next->prev = temp->prev;
  }

  delete(temp);
  }
  
}



void display(){
  Node* temp = head;
  while(temp != nullptr){
    cout << temp->data;
    if(temp->next !=nullptr){
      cout << " <-> ";
    }
    temp = temp->next;
  }
  cout << endl;
}






int main(){
insertAtHead(5);
insertAtHead(4);
insertAtHead(6);

//insertInBetween(9,6);

//deleteHead();
deleteInBetween(2);





display();





  return 0;
}