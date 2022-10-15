#include "Stack.cpp"

// function prototype declaration
Stack *PUSH(Stack *stack, string kw);
Stack *POP(Stack *stack);
Stack *MAKENULL(Stack *stack);
void TOP(Stack *stack);

// displays the program summary
void summary()
{
    cout <<"\nKitchenware Washing Machine"
        <<"\n\t[1] Add kitchenware"
        <<"\n\t[2] Wash kitchenware"
        <<"\n\t[3] Top kitchenware"
        <<"\n\t[4] Wash all"
        <<"\n\t[0] Exit"
        <<"\nEnter choice: "
        << endl;
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
            stack = PUSH(stack, kitchenware);
            break; // this breaks from the switch(), not from the loop
        case 2:
            // stack = POP(stack);
            break;
        case 3:
            TOP(stack);
            break;
        case 4:
            // stack = MAKENULL(stack);
            break;
        case 0:
            cout << "\nThe Washing Machine process has been terminated..."; // colorPrint adds color to the text; 12 corresponds to red
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

Stack *PUSH(Stack *stack, string kw)
{
    if (FULL(stack))
    {
        cout << "\nThe STACK is FULL. Cannot add kitchenware.";
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
        cout << "\nThe STACK is EMPTY. No kitchenware to wash.";
        return;
    }

    cout << "\n" << stack->topNode->data << " is next to be washed.\n";
}

Stack *POP(Stack *stack)
{
    return stack;
}

Stack *MAKENULL(Stack *stack)
{
    return stack;
}