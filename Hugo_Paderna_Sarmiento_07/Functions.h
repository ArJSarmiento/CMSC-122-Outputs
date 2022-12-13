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
    This function displays the menu
    Input: none
    Output: none
*/
void summary()
{
    cout <<"\nSorting Demonstration"
         <<"\n\t[1] Input array" 
         <<"\n\t[2] Display array"
         <<"\n\t[3] Perform SELECTION SORT"
         <<"\n\t[4] Perform MERGE SORT"
         <<"\n\t[5] Perform RADIX SORT"
         <<"\n\t[0] Exit"
         << "\nEnter choice: ";
}

/*
    This function iterates through the array and displays the items
    Input: none
    Output: none
*/
void display_list(vector<int> array)
{
    cout << "\nDisplaying array: ";
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

/*
    This function asks the user for input and adds the number into the array 
    Input: initial array 
    Output: updated array
*/

vector<int> add_item(vector<int> array)
{
    int value;
    cout << "\nEnter value: ";
    input_validation(value);
    array.push_back(value);
    return array;
}

/*
    This function performs radix sort on the array
    Input: input vector array
    Output: none
*/
void radix_sort(vector<int> array)
{

}

void merge_sort(vector<int> array)
{

}

/*
    This function performs selection sort on the array
    Input: input vector array
    Output: sorted vector array
*/
vector<int> selection_sort(vector<int> array)
{
    // Get the length of the array
    int length = array.size();

    // Loop through the entire array
    for (int i = 0; i < length - 1; i++)
    {
        // Find the minimum element in the unsorted array
        int min_idx = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
    return array;
}