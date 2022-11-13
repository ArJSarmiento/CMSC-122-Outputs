/*
    Imports necessary libraries
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

/*
    Class definition for Queue
*/
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