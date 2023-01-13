/*
    Proponents:
        Arnel Jan Sarmiento
        Francis Lloyd Hugo
        Rafael Paderna

    The program builds a minimum spanning tree (MST) based from a graph constructed
    using the information from an input file (PC01_Graph1.in and PC01_Graph2.in).
    This program uses Prim's Algorithm.

    This source code the main runtime of the program as well as function definitions.
*/

// for standard I/O
#include <iostream>
#include <fstream>
using namespace std;

// Import dependencies
#include <string>
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
    int choice, value, data;
    Graph mst;
    Graph graph;

    for (choice = 6; choice != 0;) // loop until choice is 0
    {
        summary();
        input_validation(choice);

        switch (choice)
        {
        //  Asks the user for the graph file to be loaded
        case 1:
        {
            cout << "\nWhich graph do you like to be loaded? ";
            int acceptableValues[] = {1, 2};
            input_validation(data, acceptableValues);
            graph = load_graph(data);

            cout << "\nThe Loaded Graph is: " << endl;
            display(graph);
            break;
        }
        // Constructs the MST based from the loaded graph.
        case 2:
        {
            // Checks if the a graph has been loaded
            if (graph.nodes.size() == 0)
            {
                cout << "\nPlease load a graph first.\n";
                continue;
            }
            mst = solve_mst(graph);
        }
            
            break;
        // Displays the MST resulting from the process of menu item Solve MST
        case 3:
        {
            // Checks if the MST has been constructed
            if (mst.nodes.size() == 0)
            {
                cout << "\nPlease construct the MST first.\n";
                continue;
            }
            
            cout << "\nThe Minimum Spanning Tree is: " << endl;
            display(mst);
        
            break;
        }
        // Exits the program
        case 0:
            cout << "\nExiting program...";
            break;
        // Default case
        default:
            cout << "\nInvalid input. Please try again.\n";
            continue;
        }
    }

    return 0;
}
