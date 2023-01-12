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
    Function overload for input_validation.
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
Graph load_graph(int choice)
{
    // initialize graph
    Graph graph;

    //  placeholder the lines
    string line;

    // get file according to input choice
    string filename = "PC01_Graph" + to_string(choice) + ".in";
    ifstream graphfile(filename);

    // open file and continue if exists
    if (graphfile.is_open())
    {
        // get number of vertices in the first line
        getline(graphfile, line);
        int numLines = stoi(line);

        // iterate for given the number of vertices
        for (int i = 0; i < numLines && getline(graphfile, line); i++)
        {
            string delimiter = " "; //split by space
            vector<int> arr; // initialize vector to store split values

            size_t pos = 0; // initialize position
            string token; // initialize string to store split values

            // iterate through line and split by delimiter  
            while ((pos = line.find(delimiter)) != string::npos)
            {
                token = line.substr(0, pos); 
                line.erase(0, pos + delimiter.length());
                arr.push_back(stoi(token));
            }
            arr.push_back(stoi(line));

            // add edge to graph given values of array
            graph.addEdge(arr[0], arr[1], arr[2]);
        }

        // get starting node from last line
        getline(graphfile, line);
        graph.setStartingNode(stoi(line));

        // close file
        graphfile.close();
    }

    // return graph
    return graph;
}

/*
    This function constructs the MST based from the given graph.
    Input: Graph Object
    Output: MST Object
*/
Graph solve_mst(Graph &graph)
{
    Graph mst;

    // initialize the starting node of the MST
    int start = graph.getNode(graph.startNode->value)->value;
    mst.setStartingNode(start);

    // create a set to store the vertices of the MST
    set<int> mstVertices;
    mstVertices.insert(start);

    // create a priority queue to store the edges of the MST
    priority_queue<Graph::Edge, vector<Graph::Edge>, greater<Graph::Edge>> mstEdges;

    // insert all edges connected to the starting node into the priority queue
    for (Graph::Edge *edge : graph.getNode(start)->edges)
    {
        mstEdges.push(*edge);
    }

    // while the MST is not complete
    while (mstVertices.size() < graph.nodes.size())
    {
        // get the edge with the lowest weight
        Graph::Edge edge = mstEdges.top();
        mstEdges.pop();

        // get the destination vertex of the edge
        int dest = edge.destination;

        // if the destination vertex is not in the MST
        if (mstVertices.find(dest) == mstVertices.end())
        {
            // add the destination vertex to the MST
            mstVertices.insert(dest);

            // add the edge to the MST
            mst.addEdge(edge.source, edge.destination, edge.weight);

            // insert all edges connected to the destination vertex into the priority queue
            for (Graph::Edge *edge : graph.getNode(dest)->edges)
            {
                mstEdges.push(*edge);
            }
        }
    }
    cout << "The Mininum Spanning Tree has been constructed" << endl;

    return mst;
}

/*
    This function displays the MST resulting from the process of menu item Solve MST
    Input:  MST
    Output: null
*/
void display_mst(Graph mst)
{
}