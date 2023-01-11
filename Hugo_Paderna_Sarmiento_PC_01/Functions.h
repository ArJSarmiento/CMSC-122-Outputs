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
    This function validates integer inputs. Loops until a valid input is entered given acceptable inputs
    Input: pointer of input integer, pointer of acceptable inputs
    Output: none
*/
void input_validation(int &input, int *acceptable_inputs)
{
    while (!(cin >> input))
    {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    for (int i = 0; i < sizeof(acceptable_inputs); i++)
    {
        if (input == acceptable_inputs[i])
            return;
    }
    cout << "Invalid input. Choices are either 1 or 2: ";
    input_validation(input, acceptable_inputs);
}

/*
    This function displays the menu
    Input: none
    Output: none
*/
void summary()
{
    cout << "\nMST Solver using Prim's Algorithm"
         << "\n\t[1] Load graph"
         << "\n\t[2] Build MST"
         << "\n\t[3] Display MST"
         << "\n\t[0] Exit"
         << "\nEnter choice: ";
}

/*
    This function asks the user for the graph file to be loaded
    Input: number of .in file
    Output: Graph object from .in file
*/
Graph load_graph(int data)
{
    Graph graph;

    string line;
    string firstLine;
    string lastLine;

    string filename = "PC01_Graph" + to_string(data) + ".in";
    ifstream graphfile(filename);

    if (graphfile.is_open())
    {
        getline(graphfile, firstLine) ;
        int numLines = stoi(firstLine);
        
        for (int i = 0; i < numLines && getline(graphfile, line); i++) {
            string delimiter = " "; 
            vector<int> arr;

            size_t pos = 0;
            string token;
           
            while ((pos = line.find(delimiter)) != string::npos) {
                token = line.substr(0, pos);
                line.erase(0, pos + delimiter.length());
                arr.push_back(stoi(token));
            }
            arr.push_back(stoi(line));

            graph.addEdge(arr[0], arr[1], arr[2]);
        }

        getline(graphfile, lastLine);
        graph.setStartingNode(stoi(lastLine));

        graphfile.close();
    }

    return graph;
}

/*
    This function constructs the MST based from the given graph.
    Input: Graph Object
    Output: MST Object
*/
MST *solve_mst(Graph graph)
{
}

/*
    This function displays the MST resulting from the process of menu item Solve MST
    Input:  MST
    Output: null
*/
void display_mst(MST mst)
{
}
