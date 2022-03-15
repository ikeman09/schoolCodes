// Yuson, Ike Gabriel
// Honor Statement: Upon our honor, we have accomplished this Laboratory Exercise relying upon our own honest efforts without cheating.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Precedence(char); // Determines precedence

int Operate(int, int, char); // Operate two numbers

string RemoveSpaces(string); // Remove spaces from infix input

string ParenthesisMultiplication(string); // Add asterisks to parenthesis multiplication

void InfixToPostFix(string); // Converts infix expression to postfix expression

void Evaluate(string); // Evaluates given expression

bool CheckExpression(string); // Checking if expression is valid or invalid

int main() { // Main function
  char choice; // Initialization of variable
  do {
    // Main menu
    cout << "Welcome to this Expression Evaluator program! Please choose an action to \nperform..."
         << endl; // Short program introduction
    cout << "[P] Program Description" << endl; // If choice is p or P displays program description
    cout << "[E] Evaluate Expression(s)"
         << endl; // If choice is e or E redirects to input an infix expression to be converted to a postfix expression
    cout << "[X] Exit" << endl; // If choice is to end a program
    cout << "Choice: "; // Choice prompt
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Removes next line character
    cin.clear(); // Clears input buffer
    choice = toupper(choice); // Convert lowercase to uppercase

    if (choice == 'P') { // Choice that displays program description
      bool menu = false; // Loop flag
      char choice1; // User choice

      while (!menu) {
        // Program Description
        cout << "Ike Gabriel Yuson" << endl;
        cout << "2020-06207" << endl;
        cout << "March 13, 2022" << endl;
        cout << "In the main menu, choose choice [E] to convert a desired infix expression to postfix expression."
             << endl;
        cout << "Along with the converted expression shows the corresponding evaluation." << endl;
        cout << "To exit the program choose choice [x] in the main menu." << endl;
        cout << "Would you like to go back to the main menu? Y/N" << endl;
        cout << "Choice: ";
        cin >> choice1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Removes next line character
        cin.clear(); // Clears input buffer
        choice1 = toupper(choice1); // Convert lowercase to uppercase for uniformity

        if (choice1 == 'Y') { // Choice if user wants to go back to main menu
          menu = true;
        } else if (choice1 == 'N') { // Choice if user does not want to go back to main menu
          continue;
        } else { // If input is not Y or N
          cout << "Invalid input." << endl;
        }
      }
    } else if (choice == 'E') { // Choice that converts infix to postfix expressions and evaluates them
      char choice2; // User choice
      bool menu = false; // Loop flag
      string expression; // User infix expression

      while (!menu) {
        cout << "Input an infix expression" << endl;
        cout << "Expression: ";
        getline(cin, expression); // Get user input of infix expression

        expression = RemoveSpaces(
        expression); // Calls RemoveSpaces function to remove spaces from the input for uniformity
        if (CheckExpression(
        expression)) { // If CheckExpression function returns true, then continue to convert infix expression and evaluate it
          expression = ParenthesisMultiplication(
          expression); // Adjusts the expression if parenthesis multiplication is evident
          cout << "This is your infix input: " << expression << endl; // Output infix input
          cout << "This is your postfix output: "; // Output postfix output
          InfixToPostFix(expression); // Calls InfixToPostFix function to display the postfix expression
        } else {
          cout << "Your expression is invalid. " << endl; // Prompt if CheckExpression function returns false
        }

        cout << "Input again? Y/N" << endl; // Choice if user wants to input an infix expression again
        cout << "Choice: ";
        cin >> choice2;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Removes next line character
        cin.clear(); // Clears input buffer
        choice2 = toupper(choice2); // Convert lowercase to uppercase for uniformity

        if (choice2 == 'Y') { // Choice if user inputs Y to input another infix expression
          continue;
        } else if (choice2 == 'N') { // Choice if user inputs N to go back to main menu
          menu = true; // Flag that breaks the loop
        } else {
          cout << "Invalid input." << endl; // Prompts user if input is invalid
        }
      }
    } else {
      cout << "Invalid choice" << endl; // Prompts user if input is invalid
    }

  } while (choice != 'X'); // Terminates the program if user decided to exit (E)

  return 0;
}

int Precedence(char character) { // Function that gives precedence to an operation
  if (character == '/' || character == '*' ||
      character == '%') // Gets the rank precedence of division, multiplication, and modulus
    return 2; // Assigns to integer 2
  else if (character == '+' || character == '-')  // Gets the rank precedence of addition and subtraction
    return 1; // Assigns to integer 1
  else
    return -1; // If input is neither of the 5 operations
}

int Operate(int A, int B, char op) { // Function that operates two numbers for evaluation
  switch (op) {
    case '%': // Performs modulo operation between 2 numbers
      return B % A;
    case '*': // Performs multiplication between 2 numbers
      return B * A;
    case '/': // Performs division between 2 numbers
      return B / A;
    case '+': // Performs addition between 2 numbers
      return B + A;
    case '-': // Performs subtraction betwoon 2 numbers
      return B - A;
  }
}

string RemoveSpaces(string expression) { // Function that removes the spaces of a string
  expression.erase(remove(expression.begin(), expression.end(), ' '),
                   expression.end()); // Erases all spaces from the start to the end of the string
  return expression; // Returns expression with no spaces for uniformity
}

bool
CheckExpression(string expression) { // Function that checks the validity of the infix expression inputted by the user
  int parenthesisCount = 0, operatorCount = 0, numberCount; // Stores parenthesis count, operator count, and number count

  for (int i = 0; i < expression.length(); i++) { // Loops through the expression
    if (isdigit(expression[i])) { // Checks if character in the expression is a number/digit
      numberCount++; // Increment number count if true
      operatorCount = 0; // Reset operator count to 0
      if (expression[i + 1] == '(')
        expression.insert(i + 1,
                          "*"); // Check if the next character of that digit is an open parenthesis, then add an asterisk between them
      continue; // Continue the loop, does not go into other statements
    }

    if (expression[i] == '+')
      operatorCount++; // Check if current character is an addition sign then increment operator count
    else if (expression[i] == '-') { // Check if current character is a subtraction sign
      if (expression[i - 1] == '(' && isdigit(expression[i + 1]))
        return false; // Means that a subtraction sign is in between an open parenthesis and a number, reject this input
      else if (i == 0 && isdigit(expression[i + 1]))
        return false; // Means that a subtraction sign is at the start of an expression, reject this input
      operatorCount++; // increment operator count
    } else if (expression[i] == '*')
      operatorCount++; // Check if current character is a multiplication sign (asterisk), increment operator count
    else if (expression[i] == '/')
      operatorCount++; // Check if current character is a division sign, increment operator count
    else if (expression[i] == '%')
      operatorCount++; // Check if current character is a modulo sign, increment operator count
    else if (expression[i] == '(')
      parenthesisCount++; // Check if current character is an open parenthesis, increment parenthesis count
    else if (expression[i] == ')')
      parenthesisCount--; // Check if current character is a  close parenthesis, increment parenthesis count
    else return false;

    if (parenthesisCount < 0)
      return false; // If after the current iteration parenthesis count is less than zero, which means there is a hanging close parenthesis, reject this input
    if (operatorCount > 1)
      return false; // If after the current iteration operator count is greater than one, which means there were two operators next to each other, reject this input
  }
  if (parenthesisCount > 0)
    return false; // If parenthesis count is greater than zero after the whole iteration, there is a hanging open parenthesis, reject this input
  if (operatorCount != 0)
    return false; // Operator count is not equal to zero after this whole iteration, there is an invalid character within the given expression
  if (numberCount == 0) return false; // This means that there were no numbers present in the given expression

  return true; // Return true if there is nothing wrong with the expression
}

string
ParenthesisMultiplication(string expression) { // Function that adds an asterisk in doing parenthesis multiplication
  for (int i = 0; i < expression.length(); i++) { // Loops through the expression
    if (isdigit(expression[i]) && expression[i + 1] ==
                                  '(') // Checks if current character is a digit and the next character it is an open parenthesis
      expression = expression.insert(i + 1, "*"); // Puts an asterisk between the current digit and the open parenthesis
    if (expression[i] == ')' && isdigit(
    expression[i + 1])) // Checks if current character is a closing parenthesis and the next character is a digit
      expression = expression.insert(i + 1, "*"); // Puts an asterisk between the closing parenthesis and the next digit
    if (expression[i] == ')' && expression[i + 1] ==
                                '(') // Checks if current character is a closing parenthesis and the next character is an open parenthesis
      expression = expression.insert(i + 1,
                                     "*"); // Puts an asterisk between the closing parenthesis and the next open parenthesis
  }

  return expression; // Returns the adjusted expression with parenthesis multiplication
}

void InfixToPostFix(string expression) { // Function that converts infix input to the corresponding postfix output
  stack<char> stack; // Initializes a stack
  string result; // Stores the postfix result

  for (int i = 0; i < expression.length(); i++) { // Loops through the infix expression
    char c = expression[i]; // Stores current character to c

    if (isdigit(c)) // Check if current character is a digit
      result += c; // Append digit to result
    else if (c == '(') // Check if current character is an open parenthesis
      stack.push('('); // Push open parenthesis to stack
    else if (c == ')') { // Check if current character is a closing parenthesis
      while (stack.top() != '(') { // Check the top of the stack is not an open parenthesis
        result += stack.top(); // Append the operator from the top of the stack to the result
        stack.pop(); // Pop the top of the stack
      }
      stack.pop(); // Pop the top of the stack
    } else { // If current character is an operator
      while (!stack.empty() && Precedence(expression[i]) <= Precedence(
      stack.top())) { // Check if stack is not empty, if not check the precedence of current character is less than precedence of the operator on top of the stack
        result += stack.top(); // If condition is true, append the top of the stack to the result
        stack.pop(); // Pop the top of the stack
      }
      stack.push(c); // Push the current character to the top of the stack
    }
  }

  while (!stack.empty()) { // If after the iteration above is over, check stack if empty
    result += stack.top(); // If stack is not empty append all the remaining characters from the top of the stack to the resulting
    stack.pop(); // Pop all characters inside the stack to end the loop
  }

  cout << result << endl; // Display the resulting postfix expression
  Evaluate(expression); // Call Evaluate function to evaluate the expression
}

void Evaluate(string result) { // Function that evaluates the expression
  stack<int> values; // Initialize a stack for values
  stack<char> operators; // Initialize a stack for operators

  for (int i = 0; i < result.length(); i++) { // Loop through the expression
    if (result[i] == ' ') // If current character is a space, skip it and proceed to the next iteration
      continue;
    else if (result[i] == '(') // Check if current character is an open parenthesis
      operators.push(result[i]); // Push the open parenthesis to the operators stack
    else if (isdigit(result[i])) { // Check if current character is a digit
      int value = 0; // Store a value default to 0
      while (i < result.length() && isdigit(result[i])) { // Check if current character has 2 or more digits
        value = (value * 10) + (result[i] - '0'); // If character has 2 or more digits, get its true value
        i++; // Increment until current character is no longer a digit
      }

      values.push(value); // Push the resulting value to the values stack
      i--; // Decrement i to get back to the original value of i before we checked if character has 2 or more digits
    } else if (result[i] == ')') { // check if current character is a close parenthesis
      while (!operators.empty() && operators.top() !=
                                   '(') { // Check if operators stack is not empty and that its top is not an open parenthesis
        // Operate 2 numbers
        int A = values.top(); // Value of A is the top of the values stack
        values.pop(); // Pop the top of the values stack (which is now in A)
        int B = values.top(); // Value of B is the new top of the values stack after popping the value A
        values.pop(); // Pop the top of the values stack (which is now in B)

        char op = operators.top(); // If the operator stack is not empty and its top is also not a closing parenthesis, for sure it is an operator
        operators.pop(); // Pop the top of the operator stack

        values.push(Operate(A, B, op)); // Push the value returned by the Operate function
      }

      if (!operators.empty()) // Check if operator is not empty
        operators.pop(); // Pop the top of the operator stack
    } else {
      while (!operators.empty() && Precedence(operators.top()) >= Precedence(
      result[i])) {  // Check if operator stack is not empty, if not check precedence if the current character is less than precedence of the operator on top of the operator stack
        // Operate 2 numbers
        int A = values.top();  // Value of A is the top of the values stack
        values.pop(); // Pop the top of the values stack (which is now in A)
        int B = values.top(); // Value of B is the new top of the values stack after popping the value A
        values.pop(); // Pop the top of the values stack (which is now in B)

        char op = operators.top(); // If the operator stack is not empty and its top is also not a closing parenthesis, for sure it is an operator
        operators.pop(); // Pop the top of the operator stack

        values.push(Operate(A, B, op)); // Push the value returned by the Operate function
      }
      operators.push(result[i]); // Push the current character to the operator stack
    }
  }

  // Loop through the remaining operators and evaluate
  while (!operators.empty()) { // Check if operator stack is not empty
    int A = values.top(); // Value of A is the top of the values stack
    values.pop(); // Pop the top of the values stack (which is now in A)
    int B = values.top(); // Value of B is the new top of the values stack after popping the value A
    values.pop(); // Pop the top of the values stack (which is now in B)

    char op = operators.top(); // If the operator stack is not empty and its top is also not a closing parenthesis, for sure it is an operator
    operators.pop(); // Pop the top of the operator stack

    values.push(Operate(A, B, op)); // Push the value returned by the Operate function
  }

  cout << "Evaluated output is: " << values.top()
       << endl; // Print the top of the values stack for it is the value of the given expression
}