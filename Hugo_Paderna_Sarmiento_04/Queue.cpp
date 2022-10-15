// Type Node definition
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    string order;
    Node *nextNode;

    Node(string name, string order)
    {
        this->name = name;
        this->order = order;
        this->nextNode = NULL;
    }
};

class Queue
{
public:
    Node *frontNode;
    Node *rearNode;

    Queue()
    {
        this->frontNode = NULL;
        this->rearNode = NULL;
    }
};