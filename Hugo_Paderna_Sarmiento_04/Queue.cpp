// Type Node definition
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node *prevNode;
};

class Stack
{
public:
    int max;
    Node *topNode;
    int top;

    Stack(int max)
    {
        this->max = max;
        this->topNode = NULL;
        this->top = -1;
    }
};