#include "Queue.cpp"

// function prototype declaration
Queue *INIT();
Queue *EMPTY(Queue *queue);
Node *FRONT(Queue *queue);
Queue *ENQUEUE(Node *node, Queue *queue);
Queue *DEQUEUE(Queue *queue);

// displays the program summary
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

int main()
{
    Queue *queue = INIT(); 

    int choice, value;
    string name, order;

    for (choice = 6; choice != 0;)
    {
        summary();

        cin >> choice;

        switch (choice) // use switch flow control structure
        {
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
        case 2:
            break;
        case 3:
        {
            Node *frontNode = FRONT(queue);
            (frontNode!=NULL) ? 
            cout << "\nNext order: " << frontNode->order << " of customer " << frontNode->name << ".\n" : 
            cout << "\nThe QUEUE is EMPTY. No order to serve.\n";
        }
            break;
        case 4:
            break;
        case 0:
            cout << "\nThe Washing Machine process has been terminated..."; 
        }
    }

    return 0;
}

Queue *INIT()
{
    return new Queue();
}

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

Node *FRONT(Queue *queue)
{
    return queue->frontNode;
}

Queue *EMPTY(Queue *queue)
{
    return queue;
}

Queue *DEQUEUE(Queue *queue)
{
    return queue;
}