/*
    Proponents:
        Arnel Jan Sarmiento
        Francis Lloyd Hugo
        Rafael Paderna
    
    This program creates a queue of strings.
    The user can enqueue or dequeue items, empty the queue,
    and display the first item of the queue.
    
    This source code is the main runtime of the program as well as function definitions.
*/

// import dependencies
#include "Queue.cpp"

// function prototype declaration
Queue *INIT();
bool EMPTY(Queue *queue);
Node *FRONT(Queue *queue);
Queue *ENQUEUE(Node *node, Queue *queue);
Queue *DEQUEUE(Queue *queue);

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
    This function displays the program summary with corresponding input
    Input: none
    Output: none
*/
void summary()
{
    cout <<"\nArthur's Fried Chicken Menu:"
        <<"\n\t[1] Fall in line"
        <<"\n\t[2] Serve order"
        <<"\n\t[3] Next order"
        <<"\n\t[4] Closing time"
        <<"\n\t[0] Exit"
        <<"\nEnter choice: "
        << endl;
}

/*
    This function is the main runtime of the program
    Input: none
    Output: 0
*/
int main()
{
    Queue *queue = INIT(); 

    int choice, value;
    string name, order;

    // loops until choice is 0
    for (choice = 6; choice != 0;)
    {
        // determine what to do with the program
        // with program summary
        summary();
        cin >> choice;

        switch (choice) // use switch flow control structure
        {
        // fall in line (enqueue)
        case 1:
        {
            cout << "\nYour name: ";
            cin >> name;
            cout << "\nYour order: ";
            cin >> order;
            
            Node *node = new Node(name, order);

            queue = ENQUEUE(node, queue);
        }
            break; // this breaks from the switch(), not from the loop
        // serve order (dequeue)
        case 2:
        {
            Node *frontNode = FRONT(queue);
            if (EMPTY(queue))
            {
                break;
            }
            cout << "\nNow serving " << frontNode->order << " to customer " << frontNode->name << ".\n";
            DEQUEUE(queue);
        }
            break;
        // next order (first item of queue)
        case 3:
        {
            Node *frontNode = FRONT(queue);
            (frontNode!=NULL) ? 
            cout << "\nNext order: " << frontNode->order << " of customer " << frontNode->name << ".\n" : 
            cout << "\nThe QUEUE is EMPTY. No order to serve.\n";
        }
            break;
        // closing time (empty queue)
        case 4:
        {
            Node *frontNode = FRONT(queue);

            if (EMPTY(queue))
            {
                break;
            }
            do{ // loops to delete every order and name within the queue
                cout << "\nNow serving " << frontNode->order << " to customer " << frontNode->name << ".\n"; //prints every order and name from the queue
                frontNode = frontNode->nextNode; // points to the next node of the frontNode
                queue = DEQUEUE(queue); // updates the queue
            }while (frontNode != NULL);
            cout << "\nAll orders have been served.\n";
        }
            break;
        // exit
        case 0:
            cout << "\nThe Order System has been terminated..."; 
        // default case
        default:
            cout << "\nInvalid input. Please try again.\n";
            break;
        }
    }

    return 0;
}

/*
    This function initializes the queue
    Input: none
    Output: pointer to new queue
*/
Queue *INIT()
{
    return new Queue();
}

/*
    This function adds a new item to the queue
    Input: pointer to node, pointer to queue
    Output: pointer to queue
*/
Queue *ENQUEUE(Node *node, Queue *queue)
{
    if (queue->frontNode == NULL)
    {
        queue->frontNode = node;
        queue->rearNode = node;
    }
    else
    {
        queue->rearNode->nextNode = node;
        queue->rearNode = node;
    }

    return queue;
}

/*
    This function returns the frontNode of the queue
    Input: pointer to queue
    Output: pointer to frontNode
*/
Node *FRONT(Queue *queue)
{
    return queue->frontNode;
}

/*
    This determines if the queue is empty or not.
    Input: pointer to queue
    Output: true if queue is empty, false otherwise
*/
bool EMPTY(Queue *queue)
{
    // assumes queue is empty when there is no front element
    if (FRONT(queue) == NULL)
    {
        cout << "\nThe QUEUE is EMPTY. No order to serve.\n";
        return true;
    }
    
    return false;
}

/*
    This function deletes the frontNode of the queue
    Input: pointer to queue
    Output: pointer to updated queue
*/
Queue *DEQUEUE(Queue *queue)
{
    Node *temp = queue->frontNode;

    if(queue->frontNode == NULL)
    {
        return queue;
    }

    if(queue->frontNode == queue->rearNode)
    {
        queue->frontNode = queue->rearNode = NULL;
    }
    else
    {
       queue->frontNode = temp->nextNode;
    }
    delete (temp);

    return queue;
}