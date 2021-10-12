#include "iostream"
#include  "iomanip"

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

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

Node* Insert (int, int, int, Node*);
Node* Delete (int, Node*);
Node* DeleteList (Node*);
void DisplayList (Node*);



int main(){
  Node* head = nullptr;

  int answer;
  do {
    int choice, number, position;
    cout << "[1] Add Item" << endl;
    cout << "[2] Delete Item" << endl;
    cout << "[3] Display List" << endl;
    cout << "[4] Delete List" << endl;
    cout << "[0] Exist Program" << endl;
    cout << "\nEnter choice: ";
    answer = Validator();;

    switch (answer) {
      case 1:
        cout << "[1] Start of the list" << endl;
        cout << "[2] End of the list" << endl;
        cout << "[3] Specific position" << endl;
        cout << "\nEnter choice: ";
        choice = Validator();

        switch (choice) {
          case 1:
            cout << "Enter a number: ";
            number = Validator();
            head = Insert(number, 1, 0, head);
            break;
          case 2:
            cout << "Enter a number: ";
            number = Validator();
            head = Insert(number, 2, 0, head);
            break;
          case 3:
            cout << "Enter a number: ";
            number = Validator();
            cout << "Enter a position where you want to insert that number: ";
            cin >> position;
//            position = PositionValidator(&head);
            head = Insert(number, 3, position, head);
            break;
          default:
            cout << "Invalid input.\n" << endl;
            break;
        }
        break;
      case 2:
        cout << "Enter a number you wish to delete: ";
        number = Validator();
        head = Delete(number, head);
        break;
      case 3:
        if (head == nullptr){
          cout << "List is empty\n" << endl;
          break;
        }

        DisplayList(head);
        break;
      case 4:
        head = DeleteList(head);
        break;
      case 0:
        break;
      default:
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

      if(position >= counter+1){
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