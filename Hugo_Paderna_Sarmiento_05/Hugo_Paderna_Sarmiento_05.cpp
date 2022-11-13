/*
    Proponents:
        Arnel Jan Sarmiento
        Francis Lloyd Hugo
        Rafael Paderna
    
    This program creates a Binary Search Tree of integers.
    The user can add, delete items, delete the tree, 
    find the maximum and minimum values, 
    find the predecessor and successor nodes,
    and the display the tree.

    This source code the main runtime of the program as well as function definitions.
*/

//Imports all the dependencies
#include "Node.cpp"
#include "Functions.h"

/*
    This function displays the program summary with corresponding input
    Input: none
    Output: none
*/
void summary()
{
    cout << "\nList MENU" 
         << "\n\t[1] Insert item"
         <<"\n\t[2] Delete item"
         <<"\n\t[3] Search item"
         <<"\n\t[4] Find maximum"
         <<"\n\t[5] Find minimum"
         <<"\n\t[6] Find successor"
         <<"\n\t[7] Find predecessor"
         <<"\n\t[8] Display tree"
         <<"\n\t[0] Exit"
         << "\nEnter choice: ";
}

/*
    This function is the main runtime of the program
    Input: none
    Output: 0
*/
int main()
{
    Node *root = NULL;

    int choice, position, data;

    // Loops until the user enters 0
    for (choice = 10; choice != 0;)
    {
        summary();
        input_validation(choice);

        switch (choice) // use switch flow control structure
        {
        case 1:
        {
            cout << "\nEnter a number: ";
            input_validation(position); 
            
            root = INSERT(root, position);
        }
            break; // this breaks from the switch(), not from the loop
        case 2:
        {
            cout << "\nInput number to be deleted: ";
            input_validation(data);

            root = DELETE(root, data);
        }
            break;
        case 3:
        {
            cout << "\nInput number to be searched: ";
            input_validation(data);
            
            Node *temp = SEARCH(root, data);
            if (temp != NULL)
                cout << "\nThe item, " << temp->data << " exists with count " << temp->count << "." << endl;
            else 
                cout << "\nThe item does not exist." << endl;
        }
            break;
        case 4:
        {
            Node *temp = MAX(root);
            if (temp != NULL)
                cout << "\nMaximum item: " << temp->data << "\n";
        }
            break;
        case 5:
        {
            Node *temp = MIN(root);
            if (temp != NULL)
                cout << "\nMininum Item: " <<  temp->data << "\n"; //outputs Minimum value of the BST
        }
            break;
        case 6: 
        {
            cout << "\nInput a number: ";
            input_validation(data);

            Node *temp = SUCCESSOR(root, data);
            if(temp == NULL)
                cout << "\nNo Successor Found\n";
            else
                cout << "The Successor of '" << data << "' is " << temp->data << endl;
        }
            break;
        case 7:
        {
            cout << "\nInput a number: ";
            input_validation(data);

            Node *temp = PREDECESSOR(root, data);
            if(temp == NULL)
                cout << "\nNo Predecessor Found\n";
            else
                cout << "\nThe Predecessor of '" << data << "' is " << temp->data << endl;
        }
            break;
        case 8: 
            DISPLAY(root);
            break;
        case 0: 
            cout << "\nProgram has been terminated.."; 
            break;
        default:
            cout << "\nInvalid input. Please try again.\n";
            break;
        }
    }

    return 0;
}