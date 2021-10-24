//
// Created by ikegabrielyuson on 10/22/21.
//
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Node{
public:
    string item;
    Node* next;
};


// Input validator if user inputs a character/string
int Validator() {
  int num;
  while (!(cin >> setw(1) >> num)) {
    cout << "Must be a number: ";
    cin.clear();
    cin.ignore(100, '\n');
  }

  cin.clear();
  cin.ignore(100, '\n');
  return num;
}

Node* Push(string, Node*);
Node* Pop(Node*);
Node* Wash(Node*);
void Top(Node*);

int main(){

  Node* head = nullptr;
  string item;

  int choice;
  do{
    cout << "[1] Add kitchenware" << endl;
    cout << "[2] Wash kitchenware" << endl;
    cout << "[3] Top kitchenware" << endl;
    cout << "[4] Wash all" << endl;
    cout << "[0] Exit" << endl;
    cout << "\nEnter choice: ";
    choice = Validator();

    switch(choice){
      case 0:
        break;
      case 1:
        cout << "Please enter a kitchenware you wish to be washed: ";
        getline(cin, item);
        head = Push(item, head);
        break;
      case 2:
        head = Pop(head);
        break;
      case 3:
        Top(head);
        break;
      case 4:
        head = Wash(head);
        cout << "The STACK is EMPTY. No kitchenware to wash" << endl;
        break;
      default:
        cout << "Invalid input.\n" << endl;
    }
  }while(choice != 0);
}

Node* Push(string item, Node* head){
  Node* newnode = new Node();
  newnode->item=item;
  newnode->next = head;
  head = newnode;
  return head;
}

Node* Pop(Node* head){
  if(head == nullptr){
    cout << "The STACK is EMPTY. No kitchenware to wash." << endl;
    return head;
  }
  Node* copy = head;
  head = head->next;
  cout << copy->item + " is being washed." << endl;
  delete copy;
  return head;
}

Node* Wash(Node* head){
  while(head != nullptr){
    head = Pop(head);
  }
  cout << "All kitchenware has been washed." << endl;
  return head;
}

void Top(Node* head){
  cout << head->item +" is next to be washed." << endl;
}