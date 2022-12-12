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

void radix_sort(vector<int> array)
{

}

void merge_sort(vector<int> array)
{

}

void selection_sort(vector<int> array)
{

}

void display_list(vector<int> array)
{
    cout << "\nDisplaying array: ";
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

vector<int> add_item(vector<int> array)
{
    int value;
    cout << "\nEnter value: ";
    input_validation(value);
    array.push_back(value);
    return array;
}