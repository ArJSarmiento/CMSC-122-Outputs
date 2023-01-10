/*
    Proponents:
        Arnel Jan Sarmiento
        Francis Lloyd Hugo
        Rafael Paderna
    
    This program creates an Array of number. 
    The user can add, display the list and sort the list.  
    
    This source code the main runtime of the program as well as function definitions.
*/

// Import dependencies
#include <iostream>
using namespace std;

// for standard I/O
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include "Functions.h"

/*
    This function is the main runtime of the program
    Input: none
    Output: 0
*/
int main()
{
    int choice, value;
    vector<int> array;

    for (choice = 6; choice != 0;) // loop until choice is 0
    {
        summary();
        input_validation(choice);
        
        switch (choice)
        {
        // Adds item to the array
        case 1:
            array = add_item(array);
            break;
        // Displays the items in the array
        case 2:
            display_list(array);
            break;
        //performs selection sort
        case 3:
            array = selection_sort(array);
            break;
        // performs merge sort
        case 4:
            merge_sort(array);
            break;
        //  performs radix sort
        case 5:
            radix_sort(array);
            break;
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