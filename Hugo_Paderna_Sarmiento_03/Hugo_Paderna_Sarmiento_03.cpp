// for standard I/O
#include <iostream>
using namespace std;

// for string class
#include <string>

// displays the program summary
void summary()
{
    cout << "\nList MENU"
         << "\n\t[1]Add Item"
         << "\n\t[2]Delete Item"
         << "\n\t[3]Display List"
         << "\n\t[4]Delete List"
         << "\n\t[5]Search Item"
         << "\n\t[0]Exit Program"
         << "\nEnter choice: "
         << endl;
}

int main()
{
    summary(); 

    return 0;
}