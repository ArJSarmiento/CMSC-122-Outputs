#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

// Type Node definition
typedef struct _node
{
    int data;
    struct _node *nextNode;
    struct _node *prevNode;
} Node;

// function prototype declaration
Node *add_item(Node **headptr);
Node *insert_start(Node **headptr, int value);
Node *insert_end(Node **headptr, int value);
Node *insert_specific_position(Node **headptr, int value);
Node *delete_item(Node **headptr);
void delete_list(Node **headptr);
void display_list(Node *head);
void search_item(Node **headptr);
int search_assist(Node **headptr, int val);
int list_length(Node **headptr);
void colorPrint(char arr[], int code);

int main()
{
    Node *head = NULL; // indicates an empty list

    int choice, value;

    for (choice = 6; choice != 0;) // loop until choice is 0
    {
        colorPrint("\nList MENU", 10); // colorPrint adds color to the text; 10 corresponds to green
        colorPrint("\n\t[1]Add Item", 10);
        colorPrint("\n\t[2]Delete Item", 10);
        colorPrint("\n\t[3]Display List", 10);
        colorPrint("\n\t[4]Delete List", 10);
        colorPrint("\n\t[5]Search Item", 10);
        colorPrint("\n\t[0]Exit Program", 10);
        colorPrint("\nEnter choice: ", 10);
        if (!scanf("%d", &choice))
        {
            fflush(stdin); // clean the input buffer before new scanf() call (after failed one)
            continue;      // go back to beginning of loop w/o executing rest of code in loop
        }

        switch (choice) // use switch flow control structure
        {
        case 1:
            add_item(&head); // address of head is passed; head can be modified by called function
            break;           // this breaks from the switch(), not from the loop
        case 2:
            head = delete_item(&head);
            break;
        case 3:
            display_list(head);
            break;
        case 4:
            delete_list(&head);
            break;
        case 5:
            search_item(&head);
            break;
        case 0:
            colorPrint("\nExiting program", 12); // colorPrint adds color to the text; 12 corresponds to red
        }
    }

    // frees allocated memory before exiting program
    if ((head != NULL) && (&head != NULL))
    {
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->nextNode;
            free(head);
            head = temp;
        }
    }

    return 0;
}

// this functions adds an element to the list
// returns Node *headptr
Node *add_item(Node **headptr)
{
    int choice, value;

    if ((headptr == NULL) || (*headptr == NULL)) // if the list is empty, inform the user
    {
        colorPrint("\nThe list is empty. You may not add an element at the end of the list.\n", 12);
    }

    printf("\nPlease enter the item to be added: ");
    scanf("%d", &value);

    printf("\n");
    printf("\nWhere to add the item?");
    printf("\n\t[1]Start of the list");
    printf("\n\t[2]End of the list");
    printf("\n\t[3]Specific position");
    printf("\n\t[0]Cancel");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

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

// this function adds an element at the start of the list
Node *insert_start(Node **headptr, int value)
{
    Node *ptr = (Node *)malloc(sizeof(Node)); // allocates memory for new node instance

    ptr->data = value;
    ptr->nextNode = *headptr; // links ptr to the prev head
    ptr->prevNode = NULL;     // ptr has no previous node
    *headptr = ptr;           // ptr becomes new head
    return *headptr;
}

// this function adds an element at the end of the list
Node *insert_end(Node **headptr, int value)
{
    // guard clause for empty list
    if ((headptr == NULL) || (*headptr == NULL))
    {
        colorPrint("\nThe list is empty. You may not add an element at the end of the list.\n", 12);
        return *headptr;
    }

    Node *temp_node, *ptr;

    ptr = *headptr;
    temp_node = (Node *)malloc(sizeof(Node));

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
Node *insert_specific_position(Node **headptr, int value)
{
    // guard clause for empty list
    if ((headptr == NULL) || (*headptr == NULL))
    {
        colorPrint("\nThe list is empty. You may only add at the start of the list.\n", 12);
        colorPrint("The element is now at position 1.\n", 12);
        insert_start(headptr, value);
        return *headptr;
    }

    int key, len;

    printf("\nWhich position do you want the element to be added to? ");
    scanf("%d", &key);

    Node *ptr = *headptr;
    Node *ptr2 = (Node *)malloc(sizeof(Node));
    ptr2->data = value;
    ptr2->nextNode = NULL;

    if (key == 1)
    {
        insert_start(headptr, value);
        return *headptr;
    }

    len = list_length(headptr);
    // if the position doesn't exist
    if (key < 1 || key > len + 1)
    {
        insert_end(&ptr, value);
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
}

// this function deletes an element in the list
Node *delete_item(Node **headptr)
{
    // guard clause for empty list
    if ((headptr == NULL) || (*headptr == NULL))
    {
        colorPrint("\nThe list is empty.\n", 12);
        return *headptr;
    }

    Node *temp;
    Node *head = *headptr; // copy the head pointer

    int value;
    printf("\nWhich item do you want to delete? ");
    scanf("%d", &value); // asks for the value to be deleted

    int p = search_assist(headptr, value);

    if (p == 0) // guard clause for value not found
    {
        colorPrint("\nThe list contains no such element\n", 12);
        return *headptr;
    }

    if (p == 1) // delete head if head is the value
    {
        temp = head;
        head = head->nextNode;
        head->prevNode = NULL;
        temp->nextNode = NULL;
        temp->prevNode = NULL;
        free(temp);
    }
    else
    {
        int i = 1;
        Node *before = head; // before is the node before the node at the target position

        // get the node just before the node at the target position
        while (i < p - 1)
        {
            before = before->nextNode;
            i++;
        }

        // set nextNode of the node before the node at the target position to the node after the node at the target position
        temp = before->nextNode;
        before->nextNode = temp->nextNode;
        temp->nextNode->prevNode = before;

        // free the node at the target position
        temp->nextNode = NULL;
        temp->prevNode = NULL;
        free(temp);
    }

    printf("\nThe element %d, which is at position %d, has been deleted.\n", value, p);
    return head; // returns the new head
}

// this function empties the list
void delete_list(Node **headptr)
{
    // guard clause for empty list
    if ((headptr == NULL) || (*headptr == NULL))
    {
        colorPrint("\nThe list is empty.\n", 12);
        return;
    }

    Node *temp = *headptr;

    // iterates through the list and frees each node
    while (temp != NULL)
    {
        temp = temp->nextNode;
        free(*headptr);
        *headptr = temp;
    }

    printf("\nThe list has been emptied!\n");
}

// this function displays the content of the list
void display_list(Node *head)
{
    // guard clause for empty list
    if (head == NULL)
    {
        colorPrint("\nThe list is empty.\n", 12);
        return;
    }

    // iterates through every node in the list and prints its data
    int i = 0; // Counter
    do
    {
        i++;
        printf("\n%d.) %d", i, head->data);
        head = head->nextNode;
    } while (head != NULL);
    i++;
    printf("\n");
    return;
}

// this function returns the length of the list
int list_length(Node **headptr)
{
    Node *ptr;
    ptr = *headptr;
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

// this function returns the index of searched value
int search_assist(Node **headptr, int val)
{
    // search function for given value
    Node *ptr;
    ptr = *headptr;
    int i = 1;
    do // iterate through list until value is found
    {
        if (ptr->data == val)
        {
            return i; // returns index of value
        }
        ptr = ptr->nextNode;
        i++;
    } while (ptr != NULL);
    return 0; // returns 0 if value not found
}

// this function searches an item in the list
void search_item(Node **headptr)
{
    // Guard clause for empty list
    if ((headptr == NULL) || (*headptr == NULL))
    {
        colorPrint("\nThe list is empty.\n", 12);
        return;
    }

    Node *ptr;
    ptr = *headptr;
    int value;

    printf("\nWhich item do you want to search? ");
    scanf("%d", &value); // ask for the value to be searched

    value = search_assist(headptr, value); // calls search_assist function

    if (value != 0)
    {
        printf("\nItem is located at position %d\n", value);
    }
    else
    {
        colorPrint("\nItem not found in the list\n", 12);
    }
}

// this function prints a string in a specified color and then resets the color to default
void colorPrint(char arr[], int code)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, code);

    for (int i = 0; i < strlen(arr); i++)
    {
        Sleep(10);
        printf("%c", arr[i]);
    }

    SetConsoleTextAttribute(hConsole, 7);
}