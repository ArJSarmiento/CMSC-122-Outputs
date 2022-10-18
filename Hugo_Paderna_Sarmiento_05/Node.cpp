// Type Node definition
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int count;
    Node *left;
    Node *right;
    
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
