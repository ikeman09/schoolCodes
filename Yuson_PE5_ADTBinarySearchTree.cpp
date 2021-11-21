// Yuson, Ike Gabriel
// Honor Statement: Upon our honor, we have accomplished this Laboratory Exercise relying upon our own honest efforts without cheating.

// Trees: Binary search tree implementation
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Creates a class called node
class Node {
public:
    int data, count;
    Node *left;
    Node *right;
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

Node *Insert(int, Node *); // Function that inserts a value to the BST

Node *Delete(int, Node *); // Function that deletes a value from the BST

Node *Search(int, Node *); // Function that searches a value in the BST

Node *FindMax(Node *); // Function that finds the maximum value in the BST

Node *FindMin(Node *); // Function that finds the minimum value in the BST

void FindSuc(int, Node *); // Function that finds the successor of an inputted value in the BST

void FindPred(int, Node *); // Function that finds predecessor of an inputted value in the BST

Node *NewNode(int, Node *); // Function that creates a newnode to be inserted in the BST

void Display(int, Node *); // Function that displays all the values in a BST

int main() { // Main function
  Node *root = nullptr; // Initializes an empty tree
  int data, choice; // Initialization of variables

  // Menu
  do {
    cout << "\n[1] Insert item" << endl;
    cout << "[2] Delete item" << endl;
    cout << "[3] Search item" << endl;
    cout << "[4] Find maximum" << endl;
    cout << "[5] Find minimum" << endl;
    cout << "[6] Find successor" << endl;
    cout << "[7] Find predecessor" << endl;
    cout << "[8] Display tree" << endl;
    cout << "[0] Exit" << endl;
    cout << "Enter choice: ";
    choice = Validator(); // Passes user input to validator

    switch (choice) {
      case 0: // Case that ends the program
        break;

      case 1: // Case that inserts a value to the BST
        cout << "Enter number you wish to insert: ";
        data = Validator(); // Passes input to validator
        root = Insert(data, root); // Passes root to the insert function with the parameters data and root
        break;

      case 2: // Case that deletes a value in the BST
        cout << "Enter number you wish to delete: ";
        data = Validator(); // Passes input to validator
        root = Delete(data, root); // Passes head to the delete function with the parameters data and root
        break;

      case 3: // Case that searches a value in the BST
        cout << "Enter number you wish to search: ";
        data = Validator(); // Passes the input to validator
        Node *value; // Creates a node object called value
        value = Search(data, root); // Passes value to the search function with the parameters data and root
        if (value != nullptr) { // Checks if value is present in the tree
          string result = (value->count == 1) ? "The value " + to_string(data) + " is present in the tree."
                                              : "The value " + to_string(data) +
                                                " is present in the tree with a count of " + to_string(value->count) +
                                                "."; // Notify user that value ahs been found
          cout << result << endl;
        } else { // Value is not found in the tree
          cout << "The value " + to_string(data) + " is not found in the tree." << endl; // Notify user that value not found in the tree
        }
        break;

      case 4: // Case that finds the maximum value in the BST
        Node *max; // Creates a node object called max
        max = FindMax(root); // Passes max to the find maximum function with a parameter of root
        cout << "The maximum item found in the tree is " + to_string(max->data) + "." << endl;
        break;

      case 5: // Case that finds the minimum value in the BST
        Node *min; // Creates a node object called max
        min = FindMin(root); // Passes min to the find minimum function with a parameter of root
        cout << "The minimum item found in the tree is " + to_string(min->data) + "." << endl;
        break;

      case 6: // Case that finds the successor of an inputted value
        cout << "Enter number of which you want to find its successor: ";
        data = Validator(); // Passes the input to validator
        FindSuc(data, root); // Calls the find successor function
        break;

      case 7: // Case that finds the predecessor of an inputted value
        cout << "Enter number of which you want to find its predecessor: ";
        data = Validator(); // Passes the input to validator
        FindPred(data, root); // Calls the find predecessor function
        break;

      case 8: // Case that displays all the values in the tree

        // Display menu
        cout << "[1] Inorder" << endl;
        cout << "[2] Preorder" << endl;
        cout << "[3] Postorder" << endl;
        cout << "Enter Choice: ";
        int choiceDisplay = Validator(); // Passes input to validator
        Display(choiceDisplay, root); // Calls the display function
        break;
    }
  } while (choice != 0);
}

Node *NewNode(int data) { // Newnode function
  Node *newnode = new Node(); // Allocates memory for new node object
  newnode->data = data; // The newnode's value will be assigned to the inputted value
  newnode->count = 1; // Count would be a minimum of 1
  newnode->left = nullptr; // Left of the newnode would be set to null as default
  newnode->right = nullptr; // Right of the newnode would be set to null as defualt
  return newnode;
}

Node *Insert(int data, Node *root) { // Insert function
  if (root == nullptr) { // If current root is null create new node
    root = NewNode(data); // New node creation
  } else if (data < root->data) { // Case if data is less than current root
    root->left = Insert(data, root->left); // Recursively calls insert function with new root as the left of the old root
  } else if (data > root->data) { // Case if data is greater than current root
    root->right = Insert(data, root->right); // Recursively calls insert function with new root as the right of the old root
  } else {
    root->count++; // Increments count if value already present in the tree
  }
  return root;
}

Node *Delete(int data, Node *root) { // Delete function
  if (root == nullptr) { // Value does not exist in the tree
    cout << "Value does not exist in the tree." << endl;
    return root;
  } else if (data < root->data) { // Case if data is less than current root
    root->left = Delete(data, root->left); // Recursively calls delete function with new root as the left of the old root
  } else if (data > root->data) { // Case if data is greater than current root
    root->right = Delete(data, root->right); // Recursively calls delete fucntion with new root as the right of the old root
  } else { // Valye has been found
    /**
    * Case 0: count is greater than 1
    */
    if (root->count > 1) {
      root->count--; // Count is decremented
    }
      /**
      * Case 1: root is a leaf
      */
    else if (root->left == nullptr && root->right == nullptr) {
      delete root; // Deletes memory allocated for current root
      root = nullptr; // Current root will now be null
    }
      /**
       * Case 2: root has one child
       */
    else if (root->left == nullptr) { // Case if current root has not left pointer
      Node *test = root; // Dereference current root (old root)
      root = root->right; // New current root will now be the right of the old root
      delete test; // Deletes old root
    } else if (root->right == nullptr) { // Case if current root has not right pointer
      Node *test = root; // Dereference current root (old root)
      root = root->left; // New current root will now be the left of the old root
      delete test; // Deletes old root
    }
      /**
       * Case 3: root has two children
       */
    else {
      Node *temp = FindMin(root->right); // Value of node object temp will be the minimum of the current subtree
      root->data = temp->data; // Current root data will be equal to the temp node data
      root->right = Delete(temp->data, root->right); // Recursively calls delete function with new root as the right of old root
    }
  }
  return root;
}

Node *Search(int data, Node *root) { // Search function
  if (root == nullptr) { // Case if value is not found
    return root;
  } else if (data == root->data) { // Case if value is found
    return root;
  } else if (data <= root->data) { // Case if value is less than or greater than value of current root
    return Search(data, root->left); // Recursively calls search function with new root as the left of the old root
  } else { // Case if value is greater than value of current root
    return Search(data, root->right); // Recursively calls search function with new root as the right of old root
  }
}

Node *FindMin(Node *root) { // Find minimum function
  Node *min = root; // Dereference root
  if (root == nullptr) { // Case if tree is empty
    cout << "Tree is empty" << endl;
    return root;
  }
  while (min->left != nullptr) {
    min = min->left; // Traverses left subtree until current root is null
  }
  return min; // Returns left most value of the left subtree
}


Node *FindMax(Node *root) { // Find maximum function
  Node *max = root; // Dereference root
  if (root == nullptr) { // Case if tree is empty
    cout << "Tree is empty" << endl;
    return root;
  }
  while (max->right != nullptr) {
    max = max->right; // Traverses left subtree until current root is null
  }
  return max; // Returns right most value of the right subtree
}

void FindSuc(int data, Node *root) { // Find successor function
  Node *current = Search(data, root); // Calls search function to search for value in the tree
  if (current == nullptr) { // Case if value is not found
    cout << "Value does not exist in the tree." << endl;
  }
  /**
   * Case 1: Node has right subtree
   */
  if (current->right != nullptr) {
    Node *succ = FindMin(current->right); // Successor is the minimum value in the right subtree of the current root
    cout << "The successor of " + to_string(data) + " is " + to_string(succ->data) + "." << endl;  // Notify user of successor
  }
    /**
     * Case 2: Node has no right subtree
     */
  else {
    Node *succ = nullptr; // Successor is null until found
    Node *ancestor = root; // Dereference root as ancestor
    while (ancestor != current) { // Traverse tree until ancestor is equal to current root
      if (current->data < ancestor->data) { // Making use of BST algorithm
        succ = ancestor; // Successor will be the current ancestor
        ancestor = ancestor->left; // New ancestor will be the left of old ancestor
      } else {
        ancestor = ancestor->right; // New ancestor will be the right of old ancestor
      }
    }
    if (succ == nullptr) { // Checks value of successor
      cout << to_string(data) + " has no successor" << endl; // Notify user that value has no successor
    } else {
      cout << "The successor of " + to_string(data) + " is " + to_string(succ->data) + "." << endl; // Notify user of successor
    }
  }
}

void FindPred(int data, Node *root) { // Find predecessor
  Node *current = Search(data, root); // Call search function to search for value in the tree
  if (current == nullptr) { // Case if value is not found
    cout << "Value does not exist in the tree." << endl;
  }
  /**
   * Case 1: Node has left subtree
   */
  if (current->left != nullptr) {
    Node *pred = FindMax(current->left); // Predecessor is the maximum value in the left subtree of the current root
    cout << "The predecessor of " + to_string(data) + " is " + to_string(pred->data) << endl; // Notify user of predecessor
  }
    /**
     * Case 2: Node has no left subtree
     */
  else {
    Node *pred = nullptr; // Predecessor is null until found
    Node *ancestor = root; // Dereference root as ancestor
    while (ancestor != current) { // Traverse tree until ancestor is equal to current root
      if (current->data > ancestor->data) { // Making use of BST algorithm
        pred = ancestor; // Predecessor will be current ancestor
        ancestor = ancestor->right; // New ancestor will be the right of old ancestor
      } else {
        ancestor = ancestor->left; // New ancestor will be left of old ancestor
      }
    }
    if (pred == nullptr) { // Checks value of predecessor
      cout << to_string(data) + " has no predecessor" << endl; // Notify user that value has no predecessor
    } else {
      cout << "The predecessor of " + to_string(data) + " is " + to_string(pred->data) + "." << endl; // Notify user of predecessor
    }
  }
}

void Display(int choiceDisplay, Node *root) { // Display function
  switch (choiceDisplay) {
    case 1: // Case if user inputs inorder display
      if (root != nullptr) { // Traverse tree until root is null
        // LEFT-ROOT-RIGHT
        Display(choiceDisplay, root->left);
        cout << to_string(root->data) + " ";
        Display(choiceDisplay, root->right);
      }
      break;
    case 2: // Case if user inputs preorder display
      if (root != nullptr) { // Traverse tree until root is null
        // ROOT-LEFT-RIGHT
        cout << to_string(root->data) + " ";
        Display(choiceDisplay, root->left);
        Display(choiceDisplay, root->right);
      }
      break;
    case 3:
      if (root != nullptr) { // Case if user inputs postorder display
        // LEFT-RIGHT-ROOT
        Display(choiceDisplay, root->left);
        Display(choiceDisplay, root->right);
        cout << to_string(root->data) + " ";
      }
  }
}