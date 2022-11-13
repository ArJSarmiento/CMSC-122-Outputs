void input_validation(int &input)
{
    while (!(cin >> input))
    {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
}

void input_validation_string(string &str)
{
    cin.ignore();
    getline(cin, str);
}

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

//resize array
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

Array *insert_start(Array *array, string value)
{
    return insert_helper(array, value, 0);
}

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

// this function adds an element at a specific position in the list
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

Array *delete_item(Array *array)
{
    string value;

    cout << "\nPlease enter the item to be deleted: ";
    cin >> value;

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