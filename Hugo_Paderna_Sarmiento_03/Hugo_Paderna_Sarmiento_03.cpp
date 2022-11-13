// Type Node definition
#include "Stack.cpp"

// function prototype declaration
Stack *PUSH(string kw, Stack *stack);
Stack *POP(Stack *stack);
Stack *MAKENULL(Stack *stack);
void TOP(Stack *stack);

/*
    This function displays the summary of the program with corresponding inputs
    Input: none
    Output: none
*/
void summary()
{
    cout <<"\n---------- Kitchenware Washing Machine ----------"
        <<"\n\t[1] Add kitchenware"
        <<"\n\t[2] Wash kitchenware"
        <<"\n\t[3] Top kitchenware"
        <<"\n\t[4] Wash all"
        <<"\n\t[0] Exit"
        << endl;
    cout << "\n\nEnter choice: ";
}

// Function if the main runtime of the program
int main()
{
    Stack *stack = new Stack(10); 

    int choice, value;
    string kitchenware;

    // loops until choice is 0
    for (choice = 6; choice != 0;)
    {
        summary();

        cin >> choice;

        switch (choice) // use switch flow control structure
        {
        case 1:
            cout << "\nAdd kitchenware (ex. Plate, Bowl, etc.) to be washed: ";
            cin >> kitchenware;
            stack = PUSH(kitchenware, stack);
            break; // this breaks from the switch(), not from the loop
        case 2:
            stack = POP(stack);
            break;
        case 3:
            TOP(stack);
            break;
        case 4:
            MAKENULL(stack);
            break;
        case 0:
            cout << "\nThe Washing Machine process has been terminated...\n"; // colorPrint adds color to the text; 12 corresponds to red
        default:
            cout << "\nInvalid input. Please try again.\n";
            break;
        }
    }

    return 0;
}

/*
    This function returns whether the stack is full or not
    Input: stack pointer
    Output: true if stack is full, false if stack is not full
*/
bool FULL(Stack *stack)
{
    return stack->top >= stack->max;
}

/*
    This function returns true if the stack is empty else returns false
    Input: stack pointer
    Output: true or false
*/
bool EMPTY(Stack *stack)
{
    return stack->top == -1;
}

/*
    This function adds an item to the stack
    Input: value to be added to the stack, pointer to the stack
    Output: pointer of stack with added value
*/
Stack *PUSH(string kw, Stack *stack)
{
    if (FULL(stack))
    {
        cout << "\nThe STACK is FULL. Cannot add kitchenware.\n";
        return stack;
    }

    stack->top++;
    Node *node = new Node();
    node->data = kw;
    node->prevNode = stack->topNode;
    stack->topNode = node;

    cout << "\n" << kw << " has been added to the stack\n";
    return stack;
}

/*
    This function displays the top item in the stack
    Input: pointer to the stack
    Output: none
*/
void TOP(Stack *stack)
{
    if (EMPTY(stack))
    {
        cout << "\nThe STACK is EMPTY. No kitchenware to wash.\n";
        return;
    }

    cout << "\n" << stack->topNode->data << " is next to be washed.\n";
}

Stack *POP(Stack *stack)
{
    if (EMPTY(stack))
    {
        cout << "\nThe STACK is EMPTY. No kitchenware to wash.\n";
        return stack;
    }

    cout << "\n" << stack->topNode->data << " is being washed.\n";

    Node *node = new Node(); // temporary node
    node = stack->topNode;

    if (node->prevNode == NULL) // clears old stack if last node is cleared
    {
        delete stack;
        Stack *newStack = new Stack(10); 
        return newStack;
    }

    stack->topNode = node->prevNode;
    delete node;
    
    return stack;
}

Stack *MAKENULL(Stack *stack)
{
    if (EMPTY(stack)) //guard clause if the stack is empty
    {
        cout << "\nThe STACK is EMPTY. No kitchenware to wash.\n";
        return stack;
    }

    Node *node = new Node(); // temporary node
    do{ //loops to delete every item within the stack
        cout << "\n" << stack->topNode->data << " is being washed.\n";
        node = stack->topNode;

        if (node->prevNode == NULL) // clears old stack if last node is cleared
        {
            cout << "\nAll kitchenware has been washed.\n";
            delete stack;
            Stack *newStack = new Stack(10); 
            return newStack;
        }
        stack->topNode = node->prevNode;
        delete node;
    } while (stack->topNode != NULL);

    return stack;
}