#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int value){
      data = value;
      next = nullptr;
    }
};

class CircularLinkedList{
  public:
    Node* head;

    CircularLinkedList(){
      head = nullptr;
    }

    void insertAtHead(int value){
      Node* newNode = new Node(value);
      if(head == nullptr){
        head = newNode;
        newNode->next = head;
      }
      else{
        Node* temp = head;
        while(temp->next != head){
          temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
      head = newNode;
    }
    }

    Node* traverse(int pos){
      Node* temp = head;
  
      for(int i = 1 ; i < pos && temp != nullptr && temp->next != head; i++){
        temp = temp->next;
      }
      return temp;
    }

    void insertInBetween(int v, int p){
      if(p == 0  ){
        cout<< "Invalid Position. Try 1 or greater!" <<endl;
        return;
      }

      if(p==1){
        insertAtHead(v);
        return;
      }

      Node* temp = traverse(p-1);

      Node *newNode = new Node(v);
      newNode->data = v;
      newNode->next = temp->next;
      temp->next = newNode;
    }

    void deleteAtHead(){
      if(head == nullptr){
        cout << "List is empty" << endl;
        return;
      }
      if(head->next == head){
        delete head;
        head = nullptr;
        return;
      }
      Node* temp = head;
      Node* last = head;
      while(last->next != head){
        last = last->next;
      }

      head = head->next;
      last->next = head;
      delete temp;

    }

    void deleteAtPos(int p){
      if(p <= 0){
        cout << "Invalid Position. Try 1 or greater!" << endl;
        return;
      }

      if(p == 1){
        deleteAtHead();
        return;
      }

      Node* prev = head; 
      Node* curr = head->next;

      for (int i = 2; i < p; i++) { 
        prev = curr; 
        curr = curr->next; 
        if (curr == head) { 
          cout << "Invalid Position. Try a smaller number" << endl; 
          return; 
        } 
      }

      if (curr == nullptr || curr == head) { 
        cout << "Invalid Position. Try a smaller number" << endl; 
        return; 
        } 
        prev->next = curr->next; 
        delete curr;

    }

    void display(){
      if(head == nullptr){
        cout << "List is empty" << endl;
        return;
      }
      Node *temp = head;
      do{
        cout << temp->data << " -> ";
        temp = temp->next;
      }while(temp != head);
      cout << "(head)" <<endl;
    }

    Node* search(int n){
      if(head == nullptr){
        cout << "List is empty" << endl;
        return nullptr;
      }

      Node* temp = head;
      do{
        if (temp -> data == n){
          cout << "Pointer of "<< n << " is: " << temp << endl;
          return temp;
        }
        temp = temp->next;
      } while (temp != head);

      cout << "No match found" << endl;
      return nullptr;
}

    void reverse(){
      if(head == nullptr || head->next == nullptr){
        return;
      }

      Node* prev = nullptr;
      Node *current = head;
      Node *next = nullptr;
      Node* last = head;

      while(last->next != head){
        last = last->next;
      }

      do{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
      } while (current != head);

      head->next = prev;
      head = prev;
    }

    void defaultList(){
      insertAtHead(5);
      insertAtHead(4);
      insertAtHead(3);
      insertAtHead(2);
      insertAtHead(1);

      cout<<"Default Circular List: ";
      display();
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
        deleteAtHead();
        cout << "Element at head deleted"<< endl;
      }
      if (n == 4){
        int i;
        cout << "Enter the Position you want to delete"<< endl;
        cin >> i;

        deleteAtPos(i);
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
};

int main(){
  CircularLinkedList list;
  cout << "**********************************************************************************" << endl;
  list.defaultList();
  cout << "**********************************************************************************" << endl;
  
  list.choice();

  cout<< "Circular linked list:  ";
  list.display();
  cout << endl;
  return 0;
}