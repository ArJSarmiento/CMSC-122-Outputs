#include "Node.cpp"
#include "Functions.h"

// displays the program summary
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
         <<"\n\t[9] Exit"
         << "\nEnter choice: ";
}

int main()
{
    Node *root = NULL;

    int choice, position;

    for (choice = 10; choice != 9;)
    {
        summary();

        cin >> choice;

        switch (choice) // use switch flow control structure
        {
        case 1:
        {
            cout << "\nPosition: ";
            cin >> position;
            
            root = INSERT(root, position);
        }
            break; // this breaks from the switch(), not from the loop
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8: 
            DISPLAY(root);
            break;
        case 9: 
            cout << "\nProgram has been terminated.."; 
            break;
        }
    }

    return 0;
}