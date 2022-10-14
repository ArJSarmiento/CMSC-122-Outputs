// Stack Implementation by Fiona Shane Salimbangon and Arnel Jan Sarmiento
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

// Type stack definition
typedef struct node
{
    char item[20];
    struct node *next;
} stack;

// function prototype declaration
void *PUSH(stack **topptr, char kw[]);
stack *POP(stack **topptr);
void *TOP(stack **topptr);
void *EMPTY(stack **topptr);
void colorPrint(char arr[], int code);

int main()
{
    stack *top = NULL; // initialize top pointer

    int choice, value;
    char kitchenware[20];

    for (choice = 6; choice != 0;) // loop until choice is 0
    {
        colorPrint("\nKitchenware Washing Machine", 10); // colorPrint adds color to the text; 10 corresponds to green
        colorPrint("\n\t[1] Add kitchenware", 10);
        colorPrint("\n\t[2] Wash kitchenware", 10);
        colorPrint("\n\t[3] Top kitchenware", 10);
        colorPrint("\n\t[4] Wash all", 10);
        colorPrint("\n\t[0] Exit", 10);
        colorPrint("\nEnter choice: ", 10);

        if (!scanf("%d", &choice))
        {
            colorPrint("\nInvalid input. Please try again.\n", 12);
            fflush(stdin); // clean the input buffer before new scanf() call (after failed one)
            continue;      // go back to beginning of loop w/o executing rest of code in loop
        }

        switch (choice) // use switch flow control structure
        {
        case 1:
            printf("\nAdd kitchenware (ex. Plate, Bowl, etc.) to be washed: ");
            scanf("%s", &kitchenware);
            PUSH(&top, kitchenware);
            break; // this breaks from the switch(), not from the loop
        case 2:
            top = POP(&top);
            break;
        case 3:
            TOP(&top);
            break;
        case 4:
            EMPTY(&top);
            break;
        case 0:
            colorPrint("\nThe Washing Machine process has been terminated...", 12); // colorPrint adds color to the text; 12 corresponds to red
        }
    }

    // frees allocated memory before exiting program
    if ((top != NULL) && (&top != NULL))
    {
        stack *temp = top;
        while (temp != NULL)
        {
            temp = temp->next;
            free(top);
            top = temp;
        }
    }

    return 0;
}

// pushes new element to stack
void *PUSH(stack **topptr, char kw[])
{
    int len = strlen(kw);
    if (len > 20)
    {
        colorPrint("\nThe kitchenware name is too long. Please try again.\n", 12);
        return 0;
    }

    stack *ptr = (stack *)malloc(sizeof(stack));

    for (size_t i = 0; i < len + 1; i++)
    {
        // assigns the string to the new node value, one character at a time
        ptr->item[i] = kw[i];
    }

    ptr->next = *topptr; // links ptr to the next head
    *topptr = ptr;       // ptr becomes new head

    printf("\n%s is successfully added.\n", ptr->item);
}

// removes the top element of the stack and returns new top pointer
stack *POP(stack **topptr)
{
    // guard clause for empty stack
    if ((topptr == NULL) || (*topptr == NULL))
    {
        colorPrint("\nThe STACK is EMPTY. No kitchenware to wash.\n", 12);
        return *topptr;
    }

    printf("\n%s is being washed...\n", (*topptr)->item);

    stack *temp = (*topptr)->next;
    (*topptr)->next = NULL;
    free((*topptr)); // frees the original top node from memory

    return temp; // returns the new topptr
}

// prints the the top node of the stack
void *TOP(stack **topptr)
{
    if ((topptr == NULL) || (*topptr == NULL))
    {
        colorPrint("\nThe STACK is EMPTY. No kitchenware to wash.\n", 12);
        return 0;
    }
    printf("\n%s is next to be washed.\n", (*topptr)->item);
}

// empties the stack
void *EMPTY(stack **topptr)
{
    if ((topptr == NULL) || (*topptr == NULL))
    {
        colorPrint("\nThe STACK is EMPTY. No kitchenware to wash.\n", 12);
        return 0;
    }

    while (*topptr != NULL)
    {
        *topptr = POP(topptr); // frees all the nodes in the stack
    }

    colorPrint("\nAll kitchenwares have been washed!\n", 9);
}

// prints a string in a specified color and then resets the color to default
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