/*
    import libraries for the program
*/
#include <iostream>
#include <string>
using namespace std;


/*
    Class definition for Node
*/
class Node
{
public:
    string data;
    Node *prevNode;
};

/*
    Class definition for Stack
*/
class Stack
{
public:
    int max;
    Node *topNode;
    int top;

    // Stack constructor
    Stack(int max)
    {
        this->max = max;
        this->topNode = NULL;
        this->top = -1;
    }
};