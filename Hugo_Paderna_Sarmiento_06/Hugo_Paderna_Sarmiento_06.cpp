/*
    Proponents:
        Arnel Jan Sarmiento
        Francis Lloyd Hugo
        Rafael Paderna
    
    This program contains two predefined graphs. 
    The user can traverse the graph and search an item 
    using Depth-First Search and Breadth-First Search.
    
    This source code the main runtime of the program as well as function definitions.
*/

/*
    This script imports all the standard libraries and the necessary classes
*/
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include "Graph.h"
#include "Functions.h"

/*
    This function is the main runtime of the program
    Input: none
    Output: 0
*/
int main()
{
    Graph g1 = createG1();
    Graph g2 = createG2();

    int choice, gChoice;
    char data;

    // Loops until the user enters 0
    for (choice = 5; choice != 0;)
    {
        summary();
        input_validation(choice);

        switch (choice) // use switch flow control structure
        {
        case 1: // case 1: DFS Traversal
        {
            Graph G = graphChoice(g1, g2);
            cout << "\nPerforming DFS Traversal..." << endl;
            G.DFS();
        }
        break; // this breaks from the switch(), not from the loop
        case 2: // case 2: BFS Traversal
        {
            Graph G = graphChoice(g1, g2);
            cout << "\nPerforming BFS Traversal..." << endl;
            G.BFS();
        }
        break;
        case 3: // case 3: DFS Search
        {
            cout << "\nInput character to be searched: ";
            cin >> data;
            Graph G = graphChoice(g1, g2);
            cout << "\nPerforming DFS Search...\n\n" << endl;
            G.DFS(data) ? cout << data << " is Found in the Graph" << endl: 
                cout << data << " is Not Found in the Graph" << endl;
        }
        break;
        case 4: // case 4: BFS Search
        {
            cout << "\nInput character to be searched: ";
            cin >> data;
            Graph G = graphChoice(g1, g2);
            cout << "\nPerforming BFS Search...\n\n" << endl;
            G.BFS(data) ? cout << data << " is Found in the Graph" << endl: 
                cout << data << " is Not Found in the Graph" << endl;
        }
        break;
        case 0:
            cout << "\nProgram has been terminated..";
            break;
        default:
            cout << "\nInvalid input. Please try again.\n";
            break;
        }
    }
}