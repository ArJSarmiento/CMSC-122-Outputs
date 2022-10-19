// for standard I/O
#include <iostream>
using namespace std;

// for string class
#include <string>

class Array
{
    public:
        int max;
        int len;
        string *items;

        Array(int max)
        {
            this->max = max;
            this->items =  new string[max];
            this->len = -1;
        }
};