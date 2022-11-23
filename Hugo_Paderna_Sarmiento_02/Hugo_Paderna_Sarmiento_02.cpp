/*
    Proponents:
        Arnel Jan Sarmiento
        Francis Lloyd Hugo
        Rafael Paderna
    
    This program creates a Linked List of strings. 
    The user can add, delete items, delete the list and display the list.
    
    This source code the main runtime of the program as well as function definitions.
*/

// standard I/O namespace
#include <iostream>
using namespace std;
// string type import
#include <string>
// import Node class
#include "Node.cpp"

// function prototype declaration
void input_validation(int &input);
void input_validation_string(string &str);
void summary();
Node *add_item(Node *headptr);
Node *insert_start(Node *headptr, int value);
Node *insert_end(Node *headptr, int value);
Node *insert_specific_position(Node *headptr, int value);
Node *delete_item(Node *headptr);
Node *delete_list(Node *headptr);
void display_list(Node *head);
int list_length(Node *headptr);

/*
    This function is the main runtime of the program
    Input: none
    Output: 0
*/
int main()
{
    Node *head = NULL; // indicates an empty list

    int choice, value;

    for (choice = 6; choice != 0;) // loop until choice is 0
    {
        summary();
        input_validation(choice);
        
        // switch statement to perform operations corresponding to summary
        switch (choice)
        {
        case 1:
            head = add_item(head);
            break;
        case 2:
            head = delete_item(head);
            break;
        case 3:
            display_list(head);
            break;
        case 4:
            head = delete_list(head);
            break;
        case 0:
            cout << "\nExiting program...";
            break;
        default:
            cout << "\nInvalid input. Please try again.\n";
            break;
        }
    }

    return 0;
}

/*
    This function validates integer inputs. Loops until a valid input is entered.
    Input: pointer of input integer
    Output: none
*/
void input_validation(int &input)
{
    while (!(cin >> input))
    {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
}

/*
    This function validates string inputs. Gets the entire line of input. 
    Input: pointer of input string
    Output: none
*/
void input_validation_string(string &str)
{
    cin.ignore();
    getline(cin, str);
}

/*
    This function displays the summary of the program.
    Input: none
    Output: none
*/
void summary()
{
    cout << "\nList MENU"
         << "\n\t[1]Add Item"
         << "\n\t[2]Delete Item"
         << "\n\t[3]Display List"
         << "\n\t[4]Delete List"
         << "\n\t[0]Exit Program"
         << "\nEnter choice: "
         << endl;
}

/*
    This function displays all the options in adding an item to the list.
    Exectues the function that the user chooses.
    Input: pointer of head node
    Output: pointer of head node of new list
*/
Node *add_item(Node *headptr)
{
    int choice, value;

    cout << "\nPlease enter the item to be added: ";
    input_validation(value);

    cout << "\nWhere to add the item?"
         << "\n\t[1]Start of the list"
         << "\n\t[2]End of the list"
         << "\n\t[3]Specific position"
         << "\n\t[0]Cancel"
         << "\nEnter choice: ";

    input_validation(choice);

    switch (choice)
    {
    case 1:
        return insert_start(headptr, value);
    case 2:
        return insert_end(headptr, value);
    case 3:
        return insert_specific_position(headptr, value);
    case 0:
        break;
    default:
        cout << "\nInvalid input. Please try again.\n";
        break;
    }

    return headptr;
}

/*
    This function adds an item to the start of the list.
    Input: pointer of head node, value of item to be added
    Output: pointer of head node of new list
*/
Node *insert_start(Node *headptr, int value)
{
    Node *ptr = new Node(); // allocates memory for new node instance

    ptr->data = value;
    ptr->nextNode = headptr; // links ptr to the prev head
    ptr->prevNode = NULL;    // ptr has no previous node
    headptr = ptr;           // ptr becomes new head
    return headptr;
}

/*
    This function adds an item to the end of the list.
    Input: pointer of head node, value of item to be added
    Output: pointer of head node of new list
*/
Node *insert_end(Node *headptr, int value)
{
    // guard clause for empty list
    if (headptr == NULL)
    {
        cout << "\nThe list is empty. You may not add an element at the end of the list.\n";
        return headptr;
    }

    Node *temp_node, *ptr;

    ptr = headptr;
    temp_node = new Node();

    temp_node->data = value;
    temp_node->nextNode = NULL;

    while (ptr->nextNode != NULL)
    {
        ptr = ptr->nextNode;
    }

    temp_node->prevNode = ptr;
    ptr->nextNode = temp_node;

    return headptr;
}

/*
    This function adds an item to a specific position of the list.
    Input: pointer of head node, value of item to be added
    Output: pointer of head node of new list
*/
Node *insert_specific_position(Node *headptr, int value)
{
    // guard clause for empty list
    if (&headptr == NULL)
    {
        cout << "\nThe list is empty. You may only add at the start of the list.\n"
             << "The element is now at position 1.\n";
        insert_start(headptr, value);
        return headptr;
    }

    int key, len;

    cout << "\nWhich position do you want the element to be added to? ";
    input_validation(key);

    if (key == 1)
    {
        return insert_start(headptr, value);
    }

    len = list_length(headptr);
    // if the position doesn't exist
    if (key < 1 || key > len + 1)
    {
        return insert_end(headptr, value);
    }

    Node *ptr = headptr;
    Node *ptr2 = new Node();
    ptr2->data = value;
    ptr2->nextNode = NULL;

    key--;
    while (key != 1)
    {
        ptr = ptr->nextNode;
        key--;
    }

    ptr2->nextNode = ptr->nextNode;
    ptr2->prevNode = ptr;
    ptr->nextNode->prevNode = ptr2;
    ptr->nextNode = ptr2;
    return headptr;
}

/*
    Loops through the list and returns the length of the list
    Input: head node
    Output: length of list
*/
int list_length(Node *headptr)
{
    Node *ptr = headptr;
    int len = 0;

    // iterates through list until it reaches the end
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->nextNode;
    }
    // returns number of iterated nodes
    return len;
}

/*
    This function displays all the items in the list. 
    Input: pointer of head node
    Output: none
*/
void display_list(Node *head)
{
    // guard clause for empty list
    if (head == NULL)
    {
        cout << "\nThe list is empty.\n";
        return;
    }

    // iterates through every node in the list and prints its data
    int i = 0; // Counter
    do
    {
        i++;
        cout << "\n"
             << i << ".) " << head->data << endl;
        head = head->nextNode;
    } while (head != NULL);
    cout << "\n";
}

/*
    This function deletes an element in the list.
    Input: pointer of head node, value of item to be deleted
    Output: pointer of head node of new list
*/
Node *delete_item(Node *headptr)
{
    int value, i;

    // guard clause for empty list
    if (headptr == NULL)
    {
        cout << "\nThe list is empty.\n";
        return headptr;
    }

    cout << "\nPlease enter the item to be deleted: ";
    input_validation(value);

    Node *ptr, *prev;
    ptr = headptr;
    prev = new Node();

    // deletes item at start of list
    if (ptr->data == value) 
    {
        headptr = ptr->nextNode;
        delete ptr;

        return headptr;
    }

    // determines position of item to be deleted
    while (ptr->data != value)
    {
        prev = ptr;
        ptr = ptr->nextNode;
    }

    // if item is not present in the list
    if (ptr->data != value)
    {
        delete ptr;
        cout << "\nThe list contains no such element.";
        return headptr;
    }

    prev->nextNode = ptr->nextNode;
    delete ptr;
    return headptr;
}

/*
    This function deletes the entire list.
    Input: pointer of head node
    Output: pointer to head node of new list
*/
Node *delete_list(Node *headptr)
{
    // guard clause for empty list
    if (headptr == NULL)
    {
        cout << "\nThe list is empty.\n";
        return headptr;
    }

    // set two temporary nodes
    Node *temp_node, *ptr;
    ptr = headptr;
    temp_node = new Node();
    temp_node->nextNode = NULL;

    // delete every item as list is traversed through
    while (ptr->nextNode != NULL)
    {
        temp_node = ptr->nextNode;
        delete ptr;
        ptr = temp_node;
    }

    cout << "\nThe list has been emptied.\n";

    headptr = NULL; // return null node
    return headptr;
}