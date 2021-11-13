// Yuson, Ike Gabriel
// Honor Statement: Upon our honor, we have accomplished this Laboratory Exercise relying upon our own honest efforts without cheating.

// List: Array Implementation
#include <iostream>
#include <iomanip>

using namespace std;

class Node{
public:
    string name, order;
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

Node* Init ();
bool Empty (Node*);
void Front (Node*);
Node* Closing (Node*);
Node* Enqueue (string, string, Node*);
Node* Dequeue (Node*);

int main(){
  Node* head = Init();
  string name, order;

  int choice;
  do{
    cout << "Iggy Menu" << endl;
    cout << "[1] Fall in line" << endl;
    cout << "[2} Serve order" << endl;
    cout << "[3] Next order" << endl;
    cout << "[4] Closing time" << endl;
    cout << "[0] Exit" << endl;
    cout << "Enter choice: ";
    choice = Validator();

    switch (choice) {
      case 0:
        break;
      case 1:
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your order: ";
        getline(cin, order);
        head = Enqueue(name, order, head);
        break;
      case 2:
        head = Dequeue(head);
        break;
      case 3:
        Front(head);
        break;
      case 4:
        head = Closing(head);
        break;
      default:
        cout << "Invalid input." << endl;
    }

  }while(choice != 0);
}

Node* Init(){
  Node* head = nullptr;
  return head;
}

Node* Enqueue(string name, string order, Node* head){
  Node* newnode = new Node();
  newnode->next = nullptr;
  newnode->name = name;
  newnode->order = order;

  if(head == nullptr){
    head = newnode;
    return head;
  }

  Node* test = head;

  while(test->next != nullptr){
    test = test->next;
  }
  test->next = newnode;

  return head;
}

Node* Dequeue(Node* head){
  bool isEmpty = Empty(head);
  if(isEmpty){
    cout << "The QUEUE is EMPTY. No order to serve." << endl;
    return head;
  }

  Node* test = head;
  head = head->next;
  cout << "Now serving "+ test->order + " to customer " + test->name + "." << endl;
  delete test;
  return head;
}

bool Empty (Node* head){
  bool isEmpty;

  if (head == nullptr){
    isEmpty = true;
    return isEmpty;
  }

  isEmpty = false;
  return isEmpty;
}

void Front(Node* head){
  bool isEmpty = Empty(head);
  if(isEmpty){
    cout << "The QUEUE is EMPTY. No order to serve" << endl;
  }else{
    cout << "Next order: " + head->order + " of customer " + head->name << endl;
  }
}

Node* Closing(Node* head){
  bool isEmpty = Empty(head);
  if(isEmpty){
    cout << "The QUEUE is EMPTY. No order to serve." << endl;
    return head;
  }

  while(head != nullptr){
    head = Dequeue(head);
  }

  cout << "All orders have been served. " << endl;
  return head;
}