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

Array *insert_helper(Array *array, string value, int position)
{
    Array *new_array = array;
    new_array->len++;

    if (array->len > array->max)
        new_array = new Array(array->max+10);

    for (int i = position; i <= array->len; i++)
    {
        new_array->items[i+1] = array->items[i];
    }
    new_array->items[position] = value;
    return array;
}

Array *insert_start(Array *array, string value)
{
    return insert_helper(array, value, 0);
}

Array *insert_end(Array *array, string value)
{
    // guard clause for empty list
    if (array->len < 0)
    {
        cout << "\nThe list is empty. You may not add an element at the end of the list.\n";
        return array;
    }

    return insert_helper(array, value, array->len+1);
}

// this function adds an element at a specific position in the list
Array *insert_specific_position(Array *array, string value)
{
    // guard clause for empty list
    if (array->len < 0)
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
        cin >> key;    
    } while (key > array->len+1 || key < 0);

    return insert_helper(array, value, key);
}
 
Array *add_item(Array *array)
{
    int choice;
    string value;

    if (array->len < 0) // if the list is empty, inform the user
    {
        cout << "\nThe list is empty. You may not add an element at the end of the list.\n";
    }

    cout << "\nPlease enter the item to be added: ";
    cin >> value;

    cout << "\nWhere to add the item?"
         << "\n\t[1]Start of the list"
         << "\n\t[2]End of the list"
         << "\n\t[3]Specific position"
         << "\n\t[0]Cancel"
         << "\nEnter choice: ";

    cin >> choice;

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
    }

    return array;
}

void display_list(Array *array)
{
    if (array->len < 0)
    {
        cout << "\nThe list is empty.\n";
        return;
    }

    cout << "\nList: \n";
    for (int i = 0; i <= array->len; i++)
    {
        cout << i << ".) " << array->items[i] << endl;
    }
}