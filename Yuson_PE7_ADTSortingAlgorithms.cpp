// Yuson, Ike Gabriel
// Honor Statement: Upon our honor, we have accomplished this Laboratory Exercise relying upon our own honest efforts without cheating.

#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;
#define MAXSIZE 100 // Define array size

// Creates a class called list
class List {
public:
    int items[MAXSIZE];
    int end;
};

void Insert(List*); // Function that inserts values to a list
void Display(List*); // Helper function to display current iteration of the list
void DisplayOriginal(List*, int[MAXSIZE]); // Function that displays the original list to be sorted
void SelectionSort(List*); // Function that performs selection sort
void RadixSort(List*); // Function that performs Radix sort
void CountSort(List*, int);
void MergeSort(List*, int, int); // Function that divides array into subarrays for merge sort
void Merge(List*, int, int, int); // Helper function that merges the sorted subarrays

void swap(int *a, int* b){ // Helper function to swap values of indexes for selection sort
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Validator() { // Input validator if user inputs a character/string
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
int main(){
  List list; // Creates a list object
  list.end = -1; // Sets the array size to -1 which means the list is empty

  int answer, original[MAXSIZE]; // Initialization of variables

  do{

    if(list.end == MAXSIZE){
      // todo: create new maxsize
    }

    cout << "Sorting Demonstration\n" << endl;
    cout << "[1] Input Array" << endl;
    cout << "[2] Display Array" << endl;
    cout << "[3] Perform SELECTION SORT" << endl;
    cout << "[4] Perform MERGE SORT" << endl;
    cout << "[5] Perform RADIX SORT" << endl;
    cout << "[0] Exit" << endl;
    cout << "\nEnter Choice: ";
    answer = Validator();

    switch(answer){
      case 1: // Insert function
        //todo: if user inputs another list while list is still there
        if(list.end > -1){ // Case if there exist and existing list
          int choice;
          cout << "There is already an existing list, would you like to delete the existing list and enter a new one?" << endl;
          cout << "[1] Yes" << endl;
          cout << "[2] No" << endl;
          cout << "\nEnter choice: ";
          choice = Validator(); // Validates input

          switch(choice){
            case 1: // User chooses to delete whole list and input a new one
              for (int i = 0; i <= list.end; i++) { // Deletes existing list
                list.items[i] = 0;
              }
              list.end = -1;
              cout << "Existing list has been emptied.\n" << endl;
              break;
            case 2: // User chooses not to delete existing list
              break;
            default:
              cout << "Invalid input" << endl;
              break;
          }
        }
        Insert(&list); // Calls insert function
        for(int i = 0; i < list.end + 1; i++){ // Loop that stores original list
          original[i] = list.items[i]; // There will be two lists now, one that is not touched and one that is being sorted
        }
        break;
      case 2: // DisplayOriginal function
        //todo: no list is inputted
        if(list.end == -1){ // Case where no list is to be displayed
          cout << "There is list to be displayed. Please input a list first." << endl;
          break;
        }
        DisplayOriginal(&list, original); // Displays the not touched list (original)
        break;
      case 3: { // Selection sort function
        auto start = chrono::high_resolution_clock::now(); // Start timestamp
        SelectionSort(&list); // Call selection sort function
        auto end = chrono::high_resolution_clock::now(); // End timestamp
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Get total duration of function
        cout << "Selection sort algorithm took " << duration.count() << " microseconds" << endl; // Display duration of function
        for(int i = 0; i < list.end + 1; i++){ // Returns the sorted list to the original one
          list.items[i] = original[i]; // List elements will be the same with the original
        }
        break;
      }
      case 4: { // Merge sort function
        auto start = chrono::high_resolution_clock::now(); // Start timestamp
        MergeSort(&list, 0, list.end); // Call merge sort function
        auto end = chrono::high_resolution_clock::now(); // End timestamp
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Get total duration of function
        cout << "Merge sort algorithm took " << duration.count() << " microseconds" << endl; // Display duration of function
        for(int i = 0; i < list.end + 1; i++){ // Returns the sorted list to the original one
          list.items[i] = original[i]; // List elements will be the same with original
        }
        break;
      }
      case 5: { // Radix sort function
        auto start = chrono::high_resolution_clock::now(); // Start timestamp
        RadixSort(&list); // Call merge sort function
        auto end = chrono::high_resolution_clock::now(); // End timestamp
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Get total duration of function
        cout << "Radix sort algorithm took " << duration.count() << " microseconds" << endl; // Display duration of function
        for(int i = 0; i < list.end + 1; i++){ // Returns the sorted list to the original one
          list.items[i] = original[i]; // List elements will be the same with original
        }
        break;
      }
      case 0: // Exit program
        break;
      default:
        cout << "Invalid input" << endl;
        break;
    }
  }while(answer != 0);
}

void Insert(List* list){ // Insert function
  int size; // Initialization
  cout << "Enter size of the array: "; // Enter size of array to be inserted
  size = Validator();

  for(int i = 0; i < size; i++){ // Insert all values to be inserted at the end of the list
    cout << "Enter number: ";
    list->items[i] = Validator(); // Validates input
    list->end += 1; // End will be incremented for each value to be entered
  }

}

void Display(List* list){ // Display function for sorted algorithms
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

void DisplayOriginal(List* list, int original[MAXSIZE]){ // Display function for the original list
  cout << "{ ";
  for (int i = 0; i <= list->end; i++) {
    cout << original[i];
    if (i == list->end) {
      break;
    }
    cout << ", ";
  }
  cout << " }\n" << endl;
}

void SelectionSort(List* list){ // Selection sort function
  for(int i = 0; i < list->end; i++){ // Loop that traverses the list
    int minimum = i; // Let minimum be the first index
    for(int j = i + 1; j < list->end + 1; j++){ // Loop that traverses the list
      if(list->items[j] < list->items[minimum]){ // If an item is less than the minimum value then new minimum value will be the item
        minimum = j; // New minimum value
      }
      swap(&list->items[minimum], &list->items[i]); // Swaps the index of the old minimum value to the new minimum value
      Display(list); // Displays list to track progress
    }
  }
}

void MergeSort(List* list, int start, int end){ // Merge Sort function
  if (start < end) {
    // mid is the point where the array is divided into two subarrays
    int mid = start + (end - start) / 2;

    MergeSort(list, start, mid);
    MergeSort(list, mid + 1, end);

    // Merge the sorted subarrays
    Merge(list, start, mid, end);
  }
}

void Merge(List* list, int start, int mid, int end){ // Merge helper function to merge two subarrays
  int subarrayA = mid - start + 1; // Gets index size of first array
  int subarrayB = end - mid; // Gets index size of second array

  int L[subarrayA], R[subarrayB]; // Creates temporary arrays

  for(int i = 0; i < subarrayA; i++){ // Copy data of array to be sorted to the temporary array (Left)
    L[i] = list->items[start + i];
  }

  for(int j = 0; j < subarrayB; j++){ // Copy data of array to be sorted to the temporary array (Right)
    R[j] = list->items[mid + 1 + j];
  }

  int i, j, k; // Initialization of variables for indexes of arrays
  i = 0; // Initial index of subarrayA
  j = 0; // Initial index of subarrayB
  k = start; // Initial index of merged array

  while(i < subarrayA && j < subarrayB){ // Merges temporary array to the to be sorted array (list->items)
    if(L[i] <= R[j]){
      list->items[k] = L[i];
      Display(list);
      i++;
    }else{
      list->items[k] = R[j];
      Display(list);
      j++;
    }
    k++;
  }

  while(i < subarrayA){ // Copy remaining elements of temporary left array if there is any
    list->items[k] = L[i];
    Display(list);
    i++;
    k++;
  }

  while(j < subarrayB){ // Copy remaining elements of temporary right array if there is any
    list->items[k] = R[j];
    Display(list);
    j++;
    k++;
  }
}

void RadixSort(List* list){ // Radix sort function
  int max = list->items[0]; // Maximum number is in the first index by default
  for(int i = 0; i < list->end + 1; i++){ // Loop to find the max number of the list
    if(list->items[i] > max){
      max = list->items[i];
    }
  }

  for(int exp = 1; max / exp > 0; exp *= 10){ // Count sort from ones to the highest digit
    CountSort(list, exp); // Calls count sort function
  }
}

void CountSort(List* list, int exp){
  const int max = 10; // Max size of the count array is 10 because 9 is the highest single digit number
  int output[list->end + 1]; // Output array
  int count[max]; // Count array

  for (int i = 0; i < max; ++i) // Set all count values to default by default
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < list->end + 1; i++)
    count[(list->items[i] / exp) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = list->end; i >= 0; i--) {
    output[count[(list->items[i] / exp) % 10] - 1] = list->items[i];
    DisplayOriginal(list, output);
    count[(list->items[i] / exp) % 10]--;
  }

  for (int i = 0; i < list->end + 1; i++) // Copies the output array to the original list to be sorted
    list->items[i] = output[i];
}