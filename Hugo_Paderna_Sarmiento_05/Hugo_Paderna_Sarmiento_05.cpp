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
         <<"\n\t[0] Exit"
         << "\nEnter choice: ";
}

int main()
{
    Node *root = NULL;

    int choice, position, data;

    for (choice = 10; choice != 0;)
    {
        summary();

        cin >> choice;

        switch (choice) // use switch flow control structure
        {
        case 1:
        {
            cout << "\nPosition: ";
            input_validation(position); 
            
            root = INSERT(root, position);
        }
            break; // this breaks from the switch(), not from the loop
        case 2:
        {
            cout << "\nInput number to be deleted: ";
            cin >> data;

            root = DELETE(root, data);
        }
            break;
        case 3:
        {
            cout << "\nInput number to be searched: ";
            cin >> data;
            
            Node *temp = SEARCH(root, data);
            if (temp != NULL)
                cout << "\nThe item, " << temp->data << " exists with count " << temp->count << ".";
            else 
                cout << "\nThe item does not exist.";
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
            break;
        case 6:
            break;
        case 7:
            break;
        case 8: 
            DISPLAY(root);
            break;
        case 0: 
            cout << "\nProgram has been terminated.."; 
            break;
        default:
            cout << "\nInvalid input. Please try again.\n";
            continue;
        }
    }

    return 0;
}
