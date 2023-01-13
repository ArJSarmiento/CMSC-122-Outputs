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
    This function displays the MST resulting from the process of menu item Solve MST
    Input:  Graph object
    Output: null
*/
void display(Graph g) {
    set<pair<int,int>> visited;
    for (int i = 0; i < g.nodes.size(); i++) {
        cout << g.nodes[i]->value << ": ";
        for (int j = 0; j < g.nodes[i]->edges.size(); j++) {
            // check if the edge has been outputted before
            if (visited.find(make_pair(g.nodes[i]->value, g.nodes[i]->edges[j]->destination)) == visited.end()) {
                cout << g.nodes[i]->edges[j]->destination << "(" << g.nodes[i]->edges[j]->weight << ") ";
                int destination = g.nodes[i]->edges[j]->destination;
                visited.insert(make_pair(g.nodes[i]->value, destination));
            }
        }
        cout << endl;
    }
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

    return graph;
}

/*
    This function constructs the MST based from the given graph using Prim's Algorithm
    Input: Graph Object
    Output: MST Object
*/
Graph solve_mst(Graph g)
{
    Graph mst;
    set<int> visited;
    priority_queue<Edge*, vector<Edge*>, CompareWeight> pq;

    // add the starting node to the MST
    mst.addNode(g.startNode->value);
    visited.insert(g.startNode->value);

    // add all edges starting from starting node to priority queue
    for (int i = 0; i < g.startNode->edges.size(); i++) {
        pq.push(g.startNode->edges[i]);
    }

    while (!pq.empty()) {
        Edge* edge = pq.top();
        pq.pop();

        // check if the destination of the edge is already in the MST
        if (visited.find(edge->destination) != visited.end()) {
            continue;
        }

        // add the destination of the edge to the MST
        mst.addNode(edge->destination);
        mst.addEdge(edge->source, edge->destination, edge->weight);
        visited.insert(edge->destination);

        // add all edges from the new node to the priority queue
        for (int i = 0; i < g.getNode(edge->destination)->edges.size(); i++) {
            pq.push(g.getNode(edge->destination)->edges[i]);
        }
    }

    cout << "\nThe Mininum Spanning Tree has been constructed." << endl;

    return mst;
}