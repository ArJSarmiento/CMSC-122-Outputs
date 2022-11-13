/*
    This script imports all the standard libraries and the necessary classes
*/
#include <iostream>
using namespace std;

/*
    Class definition for Node
*/
class Node
{
public:
    int data;
    int count;
    Node *left;
    Node *right;
    
    /*
        Constructors for Node
    */
    Node()
    {
        this->data = 0;
        this->count = 0;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->count = 1;
        this->left = NULL;
        this->right = NULL;
    }
    Node (int data, int count)
    {
        this->data = data;
        this->count = count;
        this->left = NULL;
        this->right = NULL;
    }
};
