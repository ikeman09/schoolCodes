// Yuson, Ike Gabriel
// Honor Statement: Upon our honor, we have accomplished this Laboratory Exercise relying upon our own honest efforts without cheating.

// List: Stack implementation using linked list.
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Creates a class called Node
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


Node* Push(string, Node*); // Function that pushes a kitchenware to the stack
Node* Pop(Node*); // Functions that pops a kitchenware from the stack
Node* Wash(Node*); // Function that pops all kitchenware from the stack
void Top(Node*); // Function that views the top of the kitchenware stack

// Main function
int main(){

  Node* head = nullptr; // Creates a Node object named head that is set to Null
  string item; // Initialization of variables

  int choice;
  do{
    cout << "[1] Add kitchenware" << endl;
    cout << "[2] Wash kitchenware" << endl;
    cout << "[3] Top kitchenware" << endl;
    cout << "[4] Wash all" << endl;
    cout << "[0] Exit" << endl;
    cout << "\nEnter choice: ";
    choice = Validator();  // Passes user input to validator

    switch(choice){
      case 0: // Case that ends the program
        break;
      case 1: // Case that pushes a kitchenware to the stack
        cout << "Please enter a kitchenware you wish to be washed: ";
        getline(cin, item); // Gets the value of item/kitchenware from the user
        head = Push(item, head); // Passes head to the push function with the parameters of the item and head
        break;
      case 2: // Case that pops a kitchenware from the stack
        head = Pop(head);  // Passes head to the pop function with a parameter of head
        break;
      case 3: // Case that views what item is at the top of the stack
        Top(head);
        break;
      case 4:
        head = Wash(head); // Passes head to the wash all function with the parameter of head
        cout << "The STACK is EMPTY. No kitchenware to wash" << endl;
        break;
      default: // Case if input is invalid
        cout << "Invalid input.\n" << endl;
    }
  }while(choice != 0);
}

Node* Push(string item, Node* head){ // Push function
  Node* newnode = new Node(); // Creates a new node object
  newnode->item=item; // The newnode's value will be assigned to the inputted item/kitchenware
  newnode->next = head; // The newnode will now also point to the head
  head = newnode; // The newnode is then considered to be the new head of the stack
  return head;
}

Node* Pop(Node* head){ // Pop function
  if(head == nullptr){ // Case if there are no items/kitchenware in the stack
    cout << "The STACK is EMPTY. No kitchenware to wash." << endl; // prints the stack is empty
    return head;
  }
  Node* copy = head; // If head is not null, dereference head
  head = head->next; // Assign new head to be the node next to the head
  cout << copy->item + " is being washed." << endl; // Print the item/kitchenware of the previous head
  delete copy; // Delete the node of the previous head
  return head;
}

Node* Wash(Node* head){ // Wash all function
  while(head != nullptr){
    head = Pop(head); // While head is not null call the pop function
  }
  cout << "All kitchenware has been washed." << endl; // Prints that all kitchenware has been washed
  return head;
}

void Top(Node* head){ // Top function
  cout << head->item +" is next to be washed." << endl; // Get the item/kitchenware of head and print it
}