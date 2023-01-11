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
    This functions acquires the largest element from an array
    Input: input vector array, size of array
    Output: max element of the array
*/
int getMax(vector<int> array) 
{   
    int max = array[0];

    // loops through the array to find the maximum element
    for (int i = 1; i < array.size(); i++) 
    {
        if (array[i] > max)
        max = array[i];
    } 
    return max;
}

/*
    This functions uses counting sort to sort the elements in the basis of significant places
    Input: input vector array, size of array, number of array elements
    Output: none
*/
void countingSort(vector<int> &array, int place) 
{
    // Calculate count of elements
    const int max = 10;
    vector<int> output(array.size());
    int count[max] = {0};

    // Calculate count of elements
    for (int i = 0; i < array.size(); i++)
        count[(array[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = array.size() - 1; i >= 0; i--) 
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    array = output;
}

/*
    This function performs radix sort on the array
    Input: input vector array
    Output: sorted vector array
*/
void radix_sort(vector<int> &array)
{
    // Get maximum element
    int max = getMax(array);

    cout << "\nDisplaying array using Radix Sort: " << endl;
    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10) 
    {
        countingSort(array, place);
        for (int i = 0; i < array.size(); i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}

/*
    This function merges two sorted vectors
    Input: vector array, left and right vectors
    Output: sorted vector array
*/
void merge(vector<int>& arr, vector<int>& left, vector<int>& right) 
{
    // sizes of left and right array
    int leftSize = left.size();
    int rightSize = right.size();

    // variables
    int i = 0, j = 0, k = 0;

    // merge two vectors into arr vector
    while (i < leftSize && j < rightSize) 
    {
        if (left[i] < right[j])
            arr[k++] = left[i++];

        else 
            arr[k++] = right[j++];
    }

    // insert remaining elements of left vector
    while (i < leftSize) 
    {
        arr[k++] = left[i++];
    }
    
    // insert remaining elements of right vector
    while (j < rightSize) 
    {
        arr[k++] = right[j++];
    }

    // print array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// merge sort function
vector<int> merge_sort(vector<int>& arr) 
{
    // array size
    int size = arr.size();

    // can't sort if array length < 2
    if (size < 2) 
        return arr;
    
    // middle of array
    int mid = size / 2;

    // declaration of left and right vectors
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    // print array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // recursive functions
    left = merge_sort(left);
    right = merge_sort(right);

    // merge sub-arrays
    merge(arr, left, right);

    // return
    return arr;
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