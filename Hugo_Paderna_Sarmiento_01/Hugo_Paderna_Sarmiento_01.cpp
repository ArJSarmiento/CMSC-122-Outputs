/*
    Proponents:
        Arnel Jan Sarmiento
        Francis Lloyd Hugo
        Rafael Paderna
    
    This program creates an Array of strings. 
    The user can add, delete items, delete the list and display the list.
    
    This source code the main runtime of the program as well as function definitions.
*/

// Import dependencies
#include "Array.cpp"
#include "Functions.h"

/*
    This function is the main runtime of the program
    Input: none
    Output: 0
*/
int main()
{
    Array *array = new Array(10);
    int choice, value;

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
        // Deletes an item of the array
        case 2:
            array = delete_item(array);
            break;
        // Displays the items in the array
        case 3:
            display_list(array);
            break;
        // Deletes the items of the array
        case 4:
            delete_list(array);
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