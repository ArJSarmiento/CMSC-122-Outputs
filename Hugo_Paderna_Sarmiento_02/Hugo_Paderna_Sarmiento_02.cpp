// for standard I/O
#include <iostream>
using namespace std;
#include <string>
#include "Node.cpp"

// function prototype declaration
void summary();
Node *add_item(Node *headptr);
Node *insert_start(Node *headptr, int value);
Node *insert_end(Node *headptr, int value);
Node *insert_specific_position(Node *headptr, int value);
Node *delete_item(Node *headptr);
Node *delete_list(Node *headptr);
void search_item(Node *headptr);
int search_assist(Node *headptr, int val);
void display_list(Node *head);
int list_length(Node headptr);

int main()
{
    Node *head = NULL; // indicates an empty list

    int choice, value;

    for (choice = 6; choice != 0;) // loop until choice is 0
    {
        summary();

        cin >> choice;
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
        case 5:
            search_item(head);
            break;
        case 0:
            cout << "\nExiting program";
        }
    }

    return 0;
}

void summary()
{
    cout << "\nList MENU"
         << "\n\t[1]Add Item"
         << "\n\t[2]Delete Item"
         << "\n\t[3]Display List"
         << "\n\t[4]Delete List"
         << "\n\t[5]Search Item"
         << "\n\t[0]Exit Program"
         << "\nEnter choice: "
         << endl;
}

Node *add_item(Node *headptr)
{
    int choice, value;

    if (headptr == NULL) // if the list is empty, inform the user
    {
        cout << "\nThe list is empty. You may not add an element at the end of the list.\n";
    }

    cout << "\nPlease enter the item to be added: ";
    cin >> value;

    cout << "\nWhere to add the item?"
         << "\n\t[1]Start of the list"
         << "\n\t[2]End of the list"
         << "\n\t[3]Specific position"
         << "\n\t[0]Cancel"
         << "\nEnter choice: ";

    cin >> choice;

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
    }

    return headptr;
}

Node *insert_start(Node *headptr, int value)
{
    Node *ptr = new Node(); // allocates memory for new node instance

    ptr->data = value;
    ptr->nextNode = headptr; // links ptr to the prev head
    ptr->prevNode = NULL;    // ptr has no previous node
    headptr = ptr;           // ptr becomes new head
    return headptr;
}

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

// this function adds an element at a specific position in the list
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
    cin >> key;

    Node *ptr = headptr;
    Node *ptr2 = new Node();
    ptr2->data = value;
    ptr2->nextNode = NULL;

    if (key == 1)
    {
        insert_start(headptr, value);
        return headptr;
    }

    len = list_length(*headptr);
    // if the position doesn't exist
    if (key < 1 || key > len + 1)
    {
        insert_end(ptr, value);
        return ptr;
    }

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

// this function returns the length of the list
int list_length(Node headptr)
{
    Node *ptr;
    ptr = &headptr;
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

// this function deletes an element in the list
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
    cin >> value;

    Node *ptr, *prev;
    ptr = headptr;
    prev = new Node();

    // deletes item at start of list
    if (ptr->data == value) 
    {
        headptr = ptr->nextNode;
        free(ptr);

        return headptr;
    }

    // determines position of item to be deleted
    while (ptr->data != value)
    {
        prev = ptr;
        ptr = ptr->nextNode;
    }

    // if item is not present in the list
    if (ptr == NULL)
    {
        return headptr;
    }

    prev->nextNode = ptr->nextNode;
    free (ptr);
    return headptr;
}

// this function deletes the entire list
Node *delete_list(Node *headptr)
{
    // guard clause for empty list
    if (headptr == NULL)
    {
        cout << "\nThe list is empty.\n";
        return headptr;
    }

    Node *temp_node, *ptr;

    ptr = headptr;
    temp_node = new Node();

    temp_node->nextNode = NULL;

    // delete every item as list is traversed through
    while (ptr->nextNode != NULL)
    {
        temp_node = ptr->nextNode;
        free(ptr);
        ptr = temp_node;
    }

    cout << "\nThe list has been emptied.\n";

    headptr = NULL;
    return headptr;
}

void search_item(Node *headptr)
{

}

int search_assist(Node *headptr, int val)
{

}
