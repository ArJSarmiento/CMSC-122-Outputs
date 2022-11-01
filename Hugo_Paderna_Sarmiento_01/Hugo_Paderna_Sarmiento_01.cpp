#include "Array.cpp"
#include "Functions.h"

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
        case 1:
            array = add_item(array);
            break;
        case 2:
            break;
        case 3:
            display_list(array);
            break;
        case 4:
            delete_list(array);
            break;
        case 0:
            cout << "\nExiting program...";
            break;
        default:
            cout << "\nInvalid input. Please try again.\n";
            continue;
        }
    }

    return 0;
}