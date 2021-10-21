// Yuson, Ike Gabriel
// Honor Statement: Upon our honor, we have accomplished this Laboratory Exercise relying upon our own honest efforts without cheating.

// List: Array Implementation
#include "iostream"
#include  "iomanip"

using namespace std;

// Creates a class called Node
class Node{
public:
    int data;
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

Node* Insert (int, int, int, Node*); // Function that deletes a value in the list
Node* Delete (int, Node*); // Function that deletes a value in the list
Node* DeleteList (Node*); // Function that removes the entire list
void DisplayList (Node*); // Function that display the entire list


// Main function
int main(){
  Node* head = nullptr; // Creates a Node object named head that is set to Null

  int answer;
  do {
    int choice, number, position; // Initialization of variables
    cout << "[1] Add Item" << endl;
    cout << "[2] Delete Item" << endl;
    cout << "[3] Display List" << endl;
    cout << "[4] Delete List" << endl;
    cout << "[0] Exist Program" << endl;
    cout << "\nEnter choice: ";
    answer = Validator();;

    switch (answer) {
      case 1: // Choice that calls the insert function
        cout << "[1] Start of the list" << endl;
        cout << "[2] End of the list" << endl;
        cout << "[3] Specific position" << endl;
        cout << "\nEnter choice: ";
        choice = Validator(); // Passes user input to validator

        switch (choice) {
          case 1: // Choice that calls the insert function that inserts item at the start of the list
            cout << "Enter a number: ";
            number = Validator(); // Passes user input to validator
            head = Insert(number, 1, 0, head);
            break;
          case 2: // Choice that calls the insert function that inserts item at the end of the list
            cout << "Enter a number: ";
            number = Validator(); // Passes user input to validator
            head = Insert(number, 2, 0, head);
            break;
          case 3: // Choice that calls the insert function that inserts item at a specific position in the list
            cout << "Enter a number: ";
            number = Validator(); // Passes user input to validator
            cout << "Enter a position where you want to insert that number: ";
            position = Validator(); // Passes user input to validator
            head = Insert(number, 3, position, head);
            break;
          default:
            cout << "Invalid input.\n" << endl;
            break;
        }
        break;
      case 2: // Choice that that calls the delete function
        cout << "Enter a number you wish to delete: ";
        number = Validator(); // Passes user input to validator
        head = Delete(number, head);
        break;
      case 3: // Choice that calls the display function
        if (head == nullptr){
          cout << "List is empty\n" << endl;
          break;
        }

        DisplayList(head);
        break;
      case 4: // Choice that calls the display function
        head = DeleteList(head);
        break;
      case 0: // Choice that exits the program
        break;
      default: // Catches error if user input is invalid
        cout << "Invalid input.\n" << endl;
        break;
    }
  } while (answer != 0);
}

Node* Insert(int number, int choice, int position, Node* head){
  Node* newnode = new Node();
  switch(choice){
    case 1:
      newnode->data = number;
      newnode->next = head;
      head = newnode;
      return head;
    case 2:
      newnode->data = number;
      newnode->next = nullptr;

      if(head == nullptr){
        head = newnode;
        return head;
      }

      Node* test;
      test = head;

      while(test->next != nullptr){
        test = test->next;
      }
      test->next = newnode;

      return head;
    case 3:
      newnode->data = number;
      newnode->next = nullptr;

      int counter = 1;
      Node* count;
      count = head;
      while(count->next != nullptr){
        count = count->next;
        counter++;
      }

      if(position == 1){
        newnode->next = head;
        head = newnode;
        return head;
      }

      if(position >= counter+1 || position < 1){
        if(head == nullptr){
          head = newnode;
          return head;
        }

        Node* tester;
        tester = head;
        while(tester->next != nullptr){
          tester = tester->next;
        }

        tester->next = newnode;
        return head;
      }

      Node* ref;
      ref = head;
      for(int a = 0; a<position-2; a++){
        ref = ref->next;
      }
      newnode->next = ref->next;
      ref->next = newnode;
      return head;
  }
}

Node* Delete(int number, Node* head){
  Node* test;
  test = head;
  bool choice = false;
  int count = 1;
  while(test!= nullptr){
    if(test->data == number){
      choice = true;
      break;
    }
    test = test->next;
    count += 1;
  }

   if(!choice){
     cout << "The list contains no such element." << endl;
     return head;
   }
   Node* temp;
   temp = head;
   if(count==1){
     head = temp->next;
     delete temp;
     return head;
   }

   for(int a=0; a<count-2; a++){
     temp = temp-> next;
   }

   Node* curr = temp->next;
   temp->next = curr->next;
   delete curr;
   return head;
}

Node* DeleteList(Node* head){
  Node* current;
  Node* nextnode;
  current = head;

  while(current != nullptr){
    nextnode = current->next;
    delete current;
    current = nextnode;
  }

  head = nullptr;
  return head;
}
void DisplayList(Node* head){
  cout << "{ ";
  while(head != nullptr){
    cout << head->data;
    if(head->next == nullptr){
      break;
    }
    cout << ", ";
    head = head->next;
  }
  cout << " }\n" << endl;
}