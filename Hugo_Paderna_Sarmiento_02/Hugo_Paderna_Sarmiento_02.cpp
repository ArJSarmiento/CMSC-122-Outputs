// for standard I/O
#include <iostream>
using namespace std;

// for string class
#include <string>

// Type Node definition
class Node {
   public:
    int data;
    Node* nextNode;
    Node* prevNode;
};

void summary();
void add_item(Node headptr);
Node insert_start(Node headptr, int value);
Node insert_end(Node headptr, int value);
Node insert_specific_position(Node headptr, int value);
Node delete_item(Node headptr);
void display_list(Node *head);
int list_length(Node headptr);

int main()
{
    Node head; // indicates an empty list

    int choice, value;

    for (choice = 6; choice != 0;) // loop until choice is 0
    {
        summary();

        cin >> choice;
        switch (choice) 
        {
            case 1:
                add_item(head); 
                break; 
            case 2:
                
                break;
            case 3:
                display_list(&head);
                break;
            case 4:
               
                break;
            case 5:
               
                break;
            case 0:
                cout <<  "\nExiting program";
        }
    }

    return 0;
}

void summary(){
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

void add_item(Node headptr)
{
    int choice, value;

    if (&headptr==NULL) // if the list is empty, inform the user
    {
        cout << "\nThe list is empty. You may not add an element at the end of the list.\n";
    }

    cout << "\nPlease enter the item to be added: ";
    cin >> value;

    cout <<"\nWhere to add the item?"
         <<"\n\t[1]Start of the list"
         <<"\n\t[2]End of the list"
         <<"\n\t[3]Specific position"
         <<"\n\t[0]Cancel"
         <<"\nEnter choice: ";

    cin >> choice;

    switch (choice)
    {
        case 1:
            insert_start(headptr, value);
            break;
        case 2:
            insert_end(headptr, value);
            break;
        case 3:
            insert_specific_position(headptr, value);
            break;
        case 0:
            break;
    }
}

Node insert_start(Node headptr, int value)
{
    Node *ptr = new Node(); // allocates memory for new node instance

    ptr->data = value;
    ptr->nextNode = &headptr; // links ptr to the prev head
    ptr->prevNode = NULL;     // ptr has no previous node
    headptr = *ptr;           // ptr becomes new head
    return headptr;
}

Node insert_end(Node headptr, int value)
{
    // guard clause for empty list
    if (&headptr == NULL)
    {
        cout <<"\nThe list is empty. You may not add an element at the end of the list.\n";
        return headptr;
    }

    Node *temp_node, *ptr;

    ptr = &headptr;
    temp_node = new Node();

    temp_node->data = value;
    temp_node->nextNode = NULL;

    while (ptr->nextNode != NULL)
    {
        ptr = ptr->nextNode;
    }

    temp_node->prevNode = ptr;
    ptr->nextNode = temp_node;
}

// this function adds an element at a specific position in the list
Node insert_specific_position(Node headptr, int value)
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

    Node *ptr = &headptr;
    Node *ptr2 = new Node();
    ptr2->data = value;
    ptr2->nextNode = NULL;

    if (key == 1)
    {
        insert_start(headptr, value);
        return headptr;
    }

    len = list_length(headptr);
    // if the position doesn't exist
    if (key < 1 || key > len + 1)
    {
        insert_end(*ptr, value);
        return *ptr;
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
        cout << "\n%d.) %d", i, head->data;
        head = head->nextNode;
    } while (head != NULL);
    i++;
    printf("\n");
    return;
}