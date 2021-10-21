// Yuson, Ike Gabriel
// Honor Statement: Upon our honor, we have accomplished this Laboratory Exercise relying upon our own honest efforts without cheating.

// List: Array Implementation
#include <iostream>
#include <iomanip>

using namespace std;
#define MAXSIZE 100 // Define array size

// Creates a class called list
class List {
public:
    int items[MAXSIZE];
    int end;
};

void Insert(int, int, int, List *); // Function that inserts a value to the list

void Delete(int, List *); // Function that deletes a value in the list

void DeleteList(List *); // Function that removes the entire list

void DisplayList(List *); // Function that display the entire list

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

// Main function
int main() {
  List list; // Creates a list object
  list.end = -1; // Sets the array to -1 which means that list is empty

  int answer;
  do {
    int choice, number, position; // Initialization of variables

    // Menu
    cout << "[1] Add Item" << endl;
    cout << "[2] Delete Item" << endl;
    cout << "[3] Display List" << endl;
    cout << "[4] Delete List" << endl;
    cout << "[0] Exist Program" << endl;
    cout << "\nEnter choice: ";
    answer = Validator();;

    switch (answer) {
      case 1: // Choice that calls the insert function
        if (list.end == MAXSIZE){
          cout << "List is already full!" << endl;
          break;
        }

        cout << "[1] Start of the list" << endl;
        cout << "[2] End of the list" << endl;
        cout << "[3] Specific position" << endl;
        cout << "\nEnter choice: ";
        choice = Validator(); // Passes user input to validator

        switch (choice) {
          case 1: // Choice that calls the insert function that inserts item at the start of the list
            cout << "Enter a number: ";
            number = Validator(); // Passes user input to validator
            Insert(number, 1, 0, &list);
            break;
          case 2: // Choice that calls the insert function that inserts item at the end of the list
            cout << "Enter a number: ";
            number = Validator();
            Insert(number, 2, 0, &list);
            break;
          case 3: // Choice that calls the insert function that inserts item at a specific position in the list
            cout << "Enter a number: ";
            number = Validator(); // Passes user input to validator
            cout << "Enter a position where you want to insert that number: ";
            position = Validator(); // Passes user input to validator
            Insert(number, 3, position, &list);
            break;
          default: // Catches error if user input is invalid
            cout << "Invalid input.\n" << endl;
            break;
        }
        break;
      case 2: // Choice that that calls the delete function
        if (list.end == -1) {
          cout << "List is empty\n" << endl;
          break;
        }
        cout << "Enter a number you wish to delete: ";
        number = Validator(); // Passes user input to validator
        Delete(number, &list);
        break;
      case 3: // Choice that calls the display function
        if (list.end == -1)
          cout << "List is empty\n" << endl;
        else
          DisplayList(&list);
        break;
      case 4: // Choice that calls the delete function
        if (list.end == -1){
          cout << "List is empty\n" << endl;
          break;
        }

        DeleteList(&list);
        break;
      case 0: // Choice that exits the program
        break;
      default: // Catches error if user input is invalid
        cout << "Invalid input.\n" << endl;
        break;
    }
  } while (answer != 0);
}

void Insert(int number, int choice, int position, List *list) {
  switch (choice) {
    case 1:
      for (int i = list->end; i >= 0; i--) {
        list->items[i + 1] = list->items[i];
      }

      list->end += 1;
      list->items[0] = number;
      break;
    case 2:
      list->end += 1;
      list->items[list->end] = number;
      break;
    case 3:
      if (position == 0) {
        list->end += 1;
        list->items[position] = number;
        break;
      }
      if (position >= list->end+1 || position < 0){
        list->end += 1;
        list->items[list->end] = number;
        break;
      }
      for (int i = list->end; i >= position; i--) {
        list->items[i + 1] = list->items[i];
      }

      list->end += 1;
      list->items[position] = number;
      break;
    default:
      cout << "Invalid input." << endl;
      break;
  }
}

void Delete(int number, List *list) {
  for (int i = 0; i <= list->end; i++) {
    if (list->items[i] == number) {
      for (int j = i; j <= list->end; j++) {
        list->items[j] = list->items[j + 1];
      }
      list->end -= 1;
      cout << "The element " << number << ", which is at position " << i << ", has been deleted\n" << endl;
      break;
    }
    if (i == list->end)
      cout << "There is no such item in the list\n" << endl;
  }
}

void DisplayList(List *list) {
  cout << "{ ";
  for (int i = 0; i <= list->end; i++) {
    cout << list->items[i];
    if (i == list->end) {
      break;
    }
    cout << ", ";
  }
  cout << " }\n" << endl;
}

void DeleteList(List *list) {
  for (int i = 0; i <= list->end; i++) {
    list->items[i] = 0;
  }
  list->end = -1;
  cout << "List has been emptied.\n" << endl;
}