// Yuson, Ike Gabriel
// Honor Statement: Upon our honor, we have accomplished this Laboratory Exercise relying upon our own honest efforts without cheating.

// List: Queue implementation using linked list
#include <iostream>
#include <iomanip>

using namespace std;

// Creates a class called Node
class Node {
public:
    string name, order;
    Node *next;
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

Node *Init(); // Function that initializes the queue

bool Empty(Node *); // Returns true or false if queue is empty

void Front(Node *); // Gets the front of the queue

Node *Closing(Node *); // Deqeues all items in the queue

Node *Enqueue(string, string, Node *); // Adds item to the queue

Node *Dequeue(Node *); // Removes item from the queue

// Main function
int main() {
  Node *head = Init(); // Initializes an empty queue
  string name, order; // Initialization of variables

  int choice;

  // Menu
  do {
    cout << "Iggy Menu" << endl;
    cout << "[1] Fall in line" << endl;
    cout << "[2} Serve order" << endl;
    cout << "[3] Next order" << endl;
    cout << "[4] Closing time" << endl;
    cout << "[0] Exit" << endl;
    cout << "Enter choice: ";
    choice = Validator(); // Passes user input to validator

    switch (choice) {
      case 0: // Case that ends the program
        break;
      case 1: // Case that takes the customer's name and order and puts it to the queue
        cout << "Enter your name: ";
        getline(cin, name); // Gets name of the customer
        cout << "Enter your order: ";
        getline(cin, order); // Gets the order of the customer
        head = Enqueue(name, order, head); // Passes the head to the enqueue function with the parameters name, order, and head
        break;
      case 2: // Case that serves the order to the customer
        head = Dequeue(head); // Passes head to the dequeue function with a parameter of head
        break;
      case 3: // Case that views the customer to be served
        Front(head); // Passes head to the front function with a parameter of head
        break;
      case 4: // Case that serves all the customers in the queue
        head = Closing(head); // Passes the head to the closing function with a parameter of head
        break;
      default: // Case if input is invalid
        cout << "Invalid input." << endl;
    }

  } while (choice != 0);
}

Node *Init() { // Initialization function
  Node *head = nullptr;
  return head; // Returns an empty head
}

Node *Enqueue(string name, string order, Node *head) { // Enqueue function
  Node *newnode = new Node(); // Creates a new node object
  newnode->next = nullptr; // newnode will be always pointing to null since newnode is always at the end of the queue
  newnode->name = name; // The newnode's name will be assigned to the inputted name
  newnode->order = order; // The newnode's order will be assigned to the inputted order

  if (head == nullptr) { // Case if head is null (empty queue)
    head = newnode; // The newnode will now become the head
    return head;
  }

  Node *test = head; // Dereference head

  while (test->next != nullptr) { // Traverse to the end of the queue
    test = test->next;
  }
  test->next = newnode; // newnode will be at the end of the queue

  return head;
}

Node *Dequeue(Node *head) { // Enqueue function
  bool isEmpty = Empty(head); // Check if queue is empty
  if (isEmpty) {
    cout << "The QUEUE is EMPTY. No order to serve." << endl; // Print if queue is empty
    return head;
  }
  // Case if queue is not empty
  Node *test = head; // Dereference head
  head = head->next; // Assign new head
  cout << "Now serving " + test->order + " to customer " + test->name + "." << endl; // Test is the old head (order being serve)
  delete test; // Delete old head
  return head;
}

bool Empty(Node *head) { // Empty function
  bool isEmpty;

  if (head == nullptr) { // Check if queue is empty
    isEmpty = true;
    return isEmpty; // Return true if queue is empty
  }

  isEmpty = false; // Return false if queue is not empty
  return isEmpty;
}

void Front(Node *head) { // Front function
  bool isEmpty = Empty(head); // Check if queue is empty
  if (isEmpty) { // If queue is empty notify user
    cout << "The QUEUE is EMPTY. No order to serve" << endl;
  } else { // If queue is not empty display the order and name of head node
    cout << "Next order: " + head->order + " of customer " + head->name << endl; // Print order and name of head node
  }
}

Node *Closing(Node *head) { // Closing function
  bool isEmpty = Empty(head); // Check if queue is empty
  if (isEmpty) { // if queue is empty notify user
    cout << "The QUEUE is EMPTY. No order to serve." << endl;
    return head;
  }

  while (head != nullptr) { // If queue is not empty serve all orders in the queue
    head = Dequeue(head); // Call dequeue function until all orders until queue is empty (serves all orders)
  }

  cout << "All orders have been served. " << endl; // Notify user that all orders had been served
  return head;
}