#include "Stack.cpp"

// function prototype declaration
Stack *PUSH(string kw, Stack *stack);
Stack *POP(Stack *stack);
Stack *MAKENULL(Stack *stack);
void TOP(Stack *stack);

// displays the program summary
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

int main()
{
    Stack *stack = new Stack(10); 

    int choice, value;
    string kitchenware;

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
        }
    }

    return 0;
}

bool FULL(Stack *stack)
{
    return stack->top >= stack->max;
}

bool EMPTY(Stack *stack)
{
    return stack->top == -1;
}

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
        free(stack);
        Stack *newStack = new Stack(10); 
        return newStack;
    }

    stack->topNode = node->prevNode;
    free(node);
    
    return stack;
}

Stack *MAKENULL(Stack *stack)
{
    if (EMPTY(stack))
    {
        cout << "\nThe STACK is EMPTY. No kitchenware to wash.\n";
        return stack;
    }

    Node *node = new Node(); // temporary node
    do{
        cout << "\n" << stack->topNode->data << " is being washed.\n";
        node = stack->topNode;

        if (node->prevNode == NULL) // clears old stack if last node is cleared
        {
            cout << "\nAll kitchenware has been washed.\n";
            free(stack);
            Stack *newStack = new Stack(10); 
            return newStack;
        }
        stack->topNode = node->prevNode;
        free(node);
    } while (stack->topNode != NULL);

    return stack;
}