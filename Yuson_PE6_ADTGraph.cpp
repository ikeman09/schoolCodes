// Yuson, Ike Gabriel
// Honor Statement: Upon our honor, we have accomplished this Laboratory Exercise relying upon our own honest efforts without cheating.

// List: Graph Implementation
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Graph{ // Creates Graph class
    int vertices; // Number of vertices of the graph
    vector<char>* adj; // Pointer of adjacent vectors
    vector<char>* vert; // Pointer of vectors vertices

    void DFSTraverse(int x, bool v[]); // Constructor for DFS Traverse
    void Search(int x, bool v[]); // Constructor for DFS Traverse Search

public:
    Graph(int count); // Function that creates vertices and adjacency of each vector
    void AddEdge(char x, char y); // Function that connects a one vertex to another
    int GetIndex(char x); // Function that gets the index of a certain vertex in a queue
    void DFS(); // Function that performs DFS Traversal
    void BFS(char x);  // Function that performs BFS Traversal that starts in vertex x
    bool SearchDFS(char n); // Function that searches for a vertex n using Depth First Search Traversal
    bool SearchBFS(char n); // Function that searches for a vertex n using Bread First Search Traversal
};

void Graph::DFSTraverse(int x, bool v[]) {
  v[x] = true; // Sets the current vertex as visited
  cout <<vert->at(x)<<" ";
  vector<char>::iterator i; // Creates an iterator that traverses all vectors' adjacent vectors
  for(i = adj[x].begin(); i!=adj[x].end(); ++i){ // Loops through all vertices
    if(!v[GetIndex(*i)]){  // Checks if vertex has not been visited yet
      DFSTraverse(GetIndex(*i), v); // Recursion
    }
  }
}

void Graph::Search(int x, bool v[]) {
  v[x] = true; // Sets the current vertex as visited
  vector<char>::iterator i; // Creates an iterator that traverses all vectors' adjacent vectors
  for(i=adj[x].begin(); i!=adj[x].end(); ++i){ // Loops through all vertices
    if(!v[GetIndex(*i)]){ // Checks if vertex has not been visited yet
      Search(GetIndex(*i), v); // Recursion
    }
  }
}

void Graph::DFS(){
  bool *visited = new bool[vertices]; // Creates a new boolean vector

  for(int i=0; i<vertices; i++){ // All vertices will be set to false by default
    visited[i] = false;
  }

  for(int i=0; i<vertices; i++){ // Traverses the boolean array
    if(!visited[i]){ // Checks value of visited element (true or false)
      DFSTraverse(i, visited);
    }
  }
}

bool Graph::SearchDFS(char n){
  bool found = false; // Sets found as false by default (flagging)
  bool *visited = new bool[vertices]; // Creates a new boolean vector

  for(int i=0; i<vertices; i++){ // All vertices will be set to false by default
    visited[i]=false;
  }

  for(int i=0;i<vertices;i++){ // Traverses the boolean array
    if(n==vert->at(i)){ // Checks if value n is found in boolean array
      found = true;  // If value is found set found to true
      break;
    }

    if(!visited[i]){
      Search(i, visited); // Use Search instead of DFSTraverse since no output of graph is needed
    }
  }

  return found; // Return found value
}

void Graph::BFS(char x){
  int curr = GetIndex(x); // Gets current index of the element the traversal wishes to start
  bool *visited = new bool[vertices]; // Creates a new boolean vector

  for(int i=0; i<vertices; i++){ // All vertices will be set to false by default
    visited[i] = false;
  }

  vector<int> queue; // Creates a queue vector
  visited[curr] = true; // Sets the first vector as visited
  queue.push_back(vert->at(curr)); // Enqueues first vertex
  vector<char>::iterator i; // Creates an iterator that traverses all vectors' adjacent vectors

  while(!queue.empty()){ // Loops until queue is empty
    x = queue.front(); // Gets current vertex
    cout << x << " "; // Displays current vertex
    curr = GetIndex(x); // Sets the current index of the vertex as curr
    queue.erase(queue.begin()); // Dequeues list

    for(i = adj[curr].begin(); i!=adj[curr].end(); i++){ // Loops all adjacent vertices
      if(!visited[GetIndex(*i)]){ // Checks if adjacent vertices are already visited
        visited[GetIndex(*i)] = true; // If not yet visited then set visited to true
        queue.push_back(vert->at(GetIndex(*i))); // Enqueue the vertex
      }
    }
  }
}

bool Graph::SearchBFS(char n) {
  int curr = 0;
  bool found = false; // Sets found as false by default
  bool *visited = new bool[vertices];

  for(int i=0; i<vertices; i++){ // All vertices will be set to false by default
    visited[i] = false;
  }

  vector<int> queue;
  visited[curr] = true; // Sets current vertex to true
  queue.push_back(vert->at(curr));
  vector<char>::iterator i;

  while(!queue.empty()){
    int x = queue.front();

    if(n == x){ // if searched item is found in the loop then exit the loop
      found = true;
      break;
    }

    curr = GetIndex(x);
    queue.erase(queue.begin());

    for(i=adj[curr].begin(); i!=adj[curr].end(); i++){
      if(!visited[GetIndex(*i)]){
        visited[GetIndex(*i)] = true;
        queue.push_back(vert->at(GetIndex(*i)));
      }
    }
  }

  return found; // Returns boolean result
}

int Graph::GetIndex(char x){
  for(int i=0; i<vertices; i++){ // Loops through the vector of vertices
    if(vert->at(i) == x){ // If found returns the index of the found vertex
      return i;
    }
  }
}

Graph::Graph(int count){
  this->vertices = count; // Sets inputted number of vertices to the graph
  adj = new vector<char>[count];
  vert = new vector<char>; // Creates array of vectors for adjacent vertices
}

void Graph::AddEdge(char x, char y) {
  if(!(std::find(vert->begin(), vert->end(), x) != vert->end())){ // Checks if inputted letter is already inside the vector
    vert->push_back(x); // Add if not yet inside the vector
  }

  int n = GetIndex(x); // Gets the index of the first variable
  int z = 0;

  if(adj[n].size() == 0){ // Checks if vector is empty
    adj[n].push_back(y); // Pushes the vertex to the vector
  }else{
    for(vector<char>::iterator i = adj[n].begin(); i != adj[n].end(); ++i){ // Case if vector is not empty
      if(*i>y){ // If adjacent vertex' value is lesser than current vertex exit the loop
        break;
      }
      z++; // Iterates z
    }
    adj[n].emplace(adj[n].begin()+z,y); // Place vertex to the first index and z
  }
}

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

int main(){ // Main function
  Graph g1(8);

  g1.AddEdge('A','B');
  g1.AddEdge('A','D');
  g1.AddEdge('A','G');

  g1.AddEdge('B','E');
  g1.AddEdge('B','A');
  g1.AddEdge('B','F');

  g1.AddEdge('C','F');
  g1.AddEdge('C','H');

  g1.AddEdge('D','A');
  g1.AddEdge('D','F');

  g1.AddEdge('E','B');
  g1.AddEdge('E','G');

  g1.AddEdge('F','D');
  g1.AddEdge('F','C');
  g1.AddEdge('F','B');

  g1.AddEdge('G','E');
  g1.AddEdge('G','A');

  g1.AddEdge('H','C');

  Graph g2(12);

  g2.AddEdge('a','c');
  g2.AddEdge('a','d');
  g2.AddEdge('a','e');
  g2.AddEdge('a','f');
  g2.AddEdge('a','k');

  g2.AddEdge('b','c');

  g2.AddEdge('c','d');
  g2.AddEdge('c','g');
  g2.AddEdge('c','b');

  g2.AddEdge('d','c');
  g2.AddEdge('d','h');
  g2.AddEdge('d','e');

  g2.AddEdge('e','d');
  g2.AddEdge('e','i');

  g2.AddEdge('f','a');
  g2.AddEdge('f','j');

  g2.AddEdge('g','c');
  g2.AddEdge('g','h');
  g2.AddEdge('g','l');

  g2.AddEdge('h','g');
  g2.AddEdge('h','d');
  g2.AddEdge('h','i');

  g2.AddEdge('i','h');
  g2.AddEdge('i','e');
  g2.AddEdge('i','j');

  g2.AddEdge('j','i');
  g2.AddEdge('j','f');

  g2.AddEdge('k','a');
  g2.AddEdge('k','l');

  g2.AddEdge('l','g');
  g2.AddEdge('l','k');

  int answer;
  do{
    cout << "\n[1] Perform DFS Traversal" << endl;
    cout << "[2] Perform BFS Traversal" << endl;
    cout << "[3] Search Item using DFS" << endl;
    cout << "[4] Search Item using BFS" << endl;
    cout << "[0] Exit" << endl;
    cout << "\nEnter choice: ";
    answer = Validator();

    switch(answer){
      case 1:
        int choice;
        cout << "[1] Graph 1" << endl;
        cout << "[2] Graph 2" << endl;
        cout << "[0] Return" << endl;
        cout << "\nEnter choice: ";
        choice = Validator();

        switch(choice){
          case 1:
            g1.DFS();
            break;
          case 2:
            g2.DFS();
            break;
          case 0:
            break;
          default:
            cout << "Invalid input" << endl;
            break;
        }
        break;

      case 2:
        int choice2;
        cout << "[1] Graph 1" << endl;
        cout << "[2] Graph 2" << endl;
        cout << "[0] Return" << endl;
        cout << "\nEnter choice: ";
        choice2 = Validator();

        switch(choice2){
          case 1:
            g1.BFS('A');
            break;
          case 2:
            g2.BFS('a');
            break;
          case 0:
            break;
          default:
            cout << "Invalid input" << endl;
            break;
        }
        break;

      case 3:
        int choice3;
        char letter;
        cout << "[1] Graph 1" << endl;
        cout << "[2] Graph 2" << endl;
        cout << "[0] Return" << endl;
        cout << "\nEnter choice: ";
        choice3 = Validator();

        switch(choice3){
          case 1:
            cout << "What letter to find?" << endl;
            cout << "Enter choice: ";
            cin >> letter;
            bool res;
            res = g1.SearchDFS(letter);

            if(!res){
              cout << "Letter is not found" << endl;
            }else{
              cout << "Letter is present in the graph" << endl;
            }

            break;
          case 2:
            cout << "What letter to find?" << endl;
            cout << "Enter choice: ";
            cin >> letter;
            bool res2;
            res2 = g2.SearchDFS(letter);

            if(!res2){
              cout << "Letter is not found" << endl;
            }else{
              cout << "Letter is present in the graph" << endl;
            }

            break;
          case 0:
            break;
          default:
            cout << "Invalid input" << endl;
            break;
        }
        break;

      case 4:
        int choice4;
        char letter2;
        cout << "[1] Graph 1" << endl;
        cout << "[2] Graph 2" << endl;
        cout << "[0] Return" << endl;
        cout << "\nEnter choice: ";
        choice4 = Validator();

        switch(choice4){
          case 1:
            cout << "What letter to find?" << endl;
            cout << "Enter choice: ";
            cin >> letter2;
            bool res;
            res = g1.SearchBFS(letter2);

            if(!res){
              cout << "Letter is not found" << endl;
            }else{
              cout << "Letter is present in the graph" << endl;
            }

            break;
          case 2:
            cout << "What letter to find?" << endl;
            cout << "Enter choice: ";
            cin >> letter2;
            bool res2;
            res2 = g2.SearchBFS(letter2);

            if(!res2){
              cout << "Letter is not found" << endl;
            }else{
              cout << "Letter is present in the graph" << endl;
            }

            break;
          case 0:
            break;
          default:
            cout << "Invalid input" << endl;
            break;
        }
        break;
      default:
        cout << "Invalid input." << endl;
        break;
    }
  }while(answer != 0);
}