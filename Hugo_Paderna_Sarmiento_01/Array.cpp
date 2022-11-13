// for standard I/O
#include <iostream>
using namespace std;

// for string class
#include <string>

/*
    This class creates an array of strings.
*/
class Array
{
    public:
        int max; // index of the maximum element
        int end; // index of the last element
        string *items; // pointer to the array of items

        Array(int max)
        {
            this->max = max;
            this->items =  new string[max];
            this->end = -1;
        }
};