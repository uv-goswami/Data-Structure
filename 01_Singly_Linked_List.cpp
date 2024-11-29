#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

 Node* head;

void insertAtHead(int value){
  Node* newNode = new Node(value);
  newNode -> data = value;
  newNode -> next = head;
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
  Node* temp = traverse(i);
  if(i<=0){
    cout << "Invalid input" << endl;
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
    temp -> next = newNode;
  }
}

void deleteHead(){
  Node* temp = head;
  head = head->next;
  delete temp;
}

void deleteInBetween(int i){
  if(i == 1){
    deleteHead();
  }

  else if(head == nullptr){
    cout << "Linked List is empty" << endl;
  }

  else {
  Node* temp = traverse(i);
  if(temp == nullptr || i == 0){
    cout << "Position " << i << " does not exist" << endl;
  }
  else{
  traverse(i-1)->next = temp->next;
  delete(temp);
  }
  }
}

void display(){
  Node* temp = head;
  while(temp != nullptr){
    cout << temp->data;
    if(temp->next !=nullptr){
      cout << " -> ";
    }
    temp = temp->next;
  }
  cout << endl;
}

void defaultList(){
  head = NULL;
  insertAtHead(5);
  insertAtHead(4);
  insertAtHead(3);
  insertAtHead(2);
  insertAtHead(1);

  cout<< "Default Singly linked list: " << endl;
  display();
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

  cout << "No Match Found" << endl;
  return nullptr;  
}

void reverse(){
  Node* current , *prev, *next;
  current = head;
  prev = nullptr;

  while (current != nullptr){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head = prev;

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

  cout<< "Singly linked list:  ";
  display();
  cout << endl;

  return 0;
}
