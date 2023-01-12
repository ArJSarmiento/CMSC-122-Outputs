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
    Input:  MST
    Output: null
*/
void display(Graph mst)
{
    set<int> visited;
    for (int i = 0; i < mst.nodes.size(); i++)
    {
        for (int j = 0; j < mst.nodes[i]->edges.size(); j++)
        {
            int destination = mst.nodes[i]->edges[j]->destination;
            int source = mst.nodes[i]->edges[j]->source;
            visited.insert(destination);

            // check if edge is already visited
            if (mst.nodes[i]->edges[j]->source == mst.nodes[i]->edges[j]->destination)
                continue;

            cout << "(" << source
            << ") -- (" << destination
            << "), W: " << mst.nodes[i]->edges[j]->weight << endl;
        }
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
    priority_queue<Edge*, vector<Edge*>, greater<Edge*>> pq;

    // Create a set to store the visited nodes
    set<int> visited;

    // Create a new graph to store the MST
    Graph mst;

    // Add the starting node to the new graph
    Node* start = mst.addNode(g.startNode->value);

    // Add the starting node to the priority queue
    pq.push(new Edge(g.startNode->value, g.startNode->value, 0));

    // While the priority queue is not empty
    while (!pq.empty()) {
        // Extract the edge with the lowest weight
        Edge* e = pq.top();
        pq.pop();

        // If both nodes of the edge have not been visited
        if (visited.find(e->source) == visited.end() || visited.find(e->destination) == visited.end()) {

            // Add the destination node to the set of visited nodes
            visited.insert(e->destination);

            // If the source node is not in the new graph, add it
            if (mst.getNode(e->source) == nullptr) {
                mst.addNode(e->source);
            }

            // If the destination node is not in the new graph, add it
            if (mst.getNode(e->destination) == nullptr) {
                mst.addNode(e->destination);
            }

            // Add the edge to the new graph
            mst.addEdge(e->source, e->destination, e->weight);

            // For each edge connected to the destination node
            for (auto edge : g.getNode(e->destination)->edges) {
                // If the destination node of the edge is not in the set of visited nodes
                if (visited.find(edge->destination) == visited.end()) {
                    // Add the edge to the priority queue
                    pq.push(edge);
                }
            }
        }
    }

    cout << "\nThe Mininum Spanning Tree has been constructed." << endl;

    return mst;
}