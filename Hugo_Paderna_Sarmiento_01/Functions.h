/*
    This function validates integer inputs. Loops until a valid input is entered.
    Input: pointer of input integer
    Output: none
*/
void input_validation(int &input)
{
    while (!(cin >> input))
    {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
}

/*
    This function validates string inputs. Gets the entire line of input. 
    Input: pointer of input string
    Output: none
*/
void input_validation_string(string &str)
{
    cin.ignore();
    getline(cin, str);
}


/*
    This function prints the intruction set of the program.
    input: none
    output: none
*/
void summary()
{
    cout << "\nList MENU"
         << "\n\t[1]Add Item"
         << "\n\t[2]Delete Item"
         << "\n\t[3]Display List"
         << "\n\t[4]Delete List"
         << "\n\t[0]Exit Program"
         << "\nEnter choice: "
         << endl;
}

/*
    This loops through and prints all the items in the list array. Prints empty statement if list is empty.
    Input: pointer of array
    Output: none
*/
void display_list(Array *array)
{
    if (array->end < 0)
    {
        cout << "\nThe list is empty.\n";
        return;
    }

    cout << "\nList: \n";
    for (int i = 0; i <= array->end; i++)
    {
        cout << i << ".) " << array->items[i] << endl;
    }
}

/*
    This function creates a new array with twice the size of the previous array. 
    Copies all the items from the previous array to the new array. 
    Deletes the previous array. 
    Input: pointer of array
    Output: pointer of resized array
*/  
Array *resize(Array *array)
{
    string *temp = new string[array->max * 2];
    for (int i = 0; i < array->max; i++)
    {
        temp[i] = array->items[i];
    }
    delete[] array->items;
    array->items = temp;
    array->max *= 2;
    return array;
}

/*
    This function adds an item to the list array. 
    Shifts all the items to the right if the list is not empty.
    If the array is full, it calls the resize function to create a new array with twice the size of the previous array. 
    Input: pointer of array, string of item to be added, integer of index of item to be added
    Output: pointer of array
*/
Array *insert_helper(Array *array, string value, int position)
{
    // check if array is full then resize
    if (array->end == array->max - 1)
    {
        array = resize(array);
    }

    for (int i = array->end+1; i > position; i--)
    {
        array->items[i] = array->items[i-1];
    }

    array->items[position] = value;
    array->end += 1;
    return array;
}

/*
    This function adds an item to the start of the list array. 
    Calls the insert_helper function to add the item to start the array.
    Input: pointer of array
    Output: pointer of array
*/
Array *insert_start(Array *array, string value)
{
    return insert_helper(array, value, 0);
}

/*
    This function adds an item to the end of the list array. 
    Calls the insert_helper function to add the item to the end of the array.
    Input: pointer of array
    Output: pointer of array
*/
Array *insert_end(Array *array, string value)
{
    // guard clause for empty list
    if (array->end < 0)
    {
        cout << "\nThe list is empty. You may not add an element at the end of the list.\n";
        return array;
    }

    return insert_helper(array, value, array->end+1);
}

/*
    This function adds an item to a specific position in the list array. 
    Calls the insert_helper function to add the item to the array.
    Input: pointer of array
    Output: pointer of array
*/
Array *insert_specific_position(Array *array, string value)
{
    // guard clause for empty list
    if (array->end < 0)
    {
        cout << "\nThe list is empty. You may only add at the start of the list.\n"
             << "The element is now at position 1.\n";
        insert_start(array, value);
        return array;
    }

    int key;
    do
    {
        cout << "\nWhich position do you want the element to be added to? ";
        input_validation(key);
    } while (key > array->end+1 || key < 0);

    return insert_helper(array, value, key);
}

/*
    This function displays the options of inserting an item into the list array.
    And calls the appropriate function to add the item to the array.
    Input: pointer of array
    Output: pointer of array
*/
Array *add_item(Array *array)
{
    int choice;
    string value;

    cout << "\nPlease enter the item to be added: ";
    input_validation_string(value);

    
    for (choice = 4; choice != 0;) // loop until choice is 0
    {
        cout << "\nWhere to add the item?"
            << "\n\t[1]Start of the list"
            << "\n\t[2]End of the list"
            << "\n\t[3]Specific position"
            << "\n\t[0]Cancel"
            << "\nEnter choice: ";

        input_validation(choice);

        switch (choice)
        {
        case 1:
            return insert_start(array, value);
        case 2:
            return insert_end(array, value);
        case 3:
            return insert_specific_position(array, value);
        case 0:
            break;
        default:
            cout << "\nInvalid input. Please try again.\n";
            break;
        }
    }

    return array;
}

/*
    This function deletes an item from the array.
    Input: pointer of array
    Output: pointer of new array with a deleted value
*/
Array *delete_item(Array *array)
{
    string value;

    cout << "\nPlease enter the item to be deleted: ";
    input_validation_string(value);

    int i, j, position;
    for (i = 0; i <= array->end; i++)
    {
        if (array->items[i] == value)
        {
            {
                for (j = i; j < array->end; j++);
                {
                    array->items[j] = array->items[j+1];
                }
            }
            position = i;
            break;
        }
    }

    if (position == 0)
    {
        cout << ("\nThe list contains no such element.");
        return array;
    }

    else
    {
        cout << "\nThe element " << value << ", which is at position " << position << ", has been deleted.";

        for (i = position; i < array->end-1; i++)
        {
            array->items[i] = array->items[i+1];
        }

        return array;
    }

    return array;
}

Array *delete_list(Array *array)
{
    // guard clause for empty list
    if (array->end < 0)
    {
        cout << "\nThe list is empty.\n";
        return array;
    }

    cout << "\nThe list has been emptied." << endl;
    delete array;
    Array *newarray = new Array(10); //clears the previous list by initializing a new array
    return newarray;
}