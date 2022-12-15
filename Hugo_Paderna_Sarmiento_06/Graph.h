/*
    Class definition for Graph
*/
class Graph
{
    private:
        // Node struct for representing a node in the graph
        class Node {
            public:
                char value;
                vector<Node*> neighbors;

                Node(char val) {
                    value = val;
                }
        };

        // List for storing all of the nodes in the graph
        vector<Node*> nodes;

    public:

        /*
            This function adds a node to the graph.
            Input: value of node
            Output: none
        */

        void addNode(char value)
        {
            Node* node = new Node(value);
            nodes.push_back(node);
        }

        /*
            This is a constructor for the Graph class.
            Input: array of values, size of array
            Output: graph with input size and values
        */

        Graph(char *values, int size)
        {
            for (int i = 0; i < size; i++)
            {
                addNode(values[i]);
            }
        }

        /*
            This function traverses a graph using Depth-First Search.
            Input: none
            Output: Displays traversed graph using DFS
        */
        void DFS()
        {
            //initialize Stack
            stack<Node*> s;

            //initialize visited list
            set<char> visited;

            //push first node
            Node* node = nodes[0];
            s.push(node);

            while (!s.empty())
            {
                node = s.top();
                s.pop();

                if (visited.find(node->value) == visited.end())
                {
                    visited.insert(node->value);
                    cout << node->value << endl;

                    //iterate through neighbors in reverse
                    for (int i = node->neighbors.size() - 1; i >= 0; i--)
                    {
                        Node* neighbor = node->neighbors[i];
                        // if neighbor is not visited, push to stack
                        if (visited.find(neighbor->value) == visited.end())
                        {
                            s.push(neighbor);
                        }
                    }
                }
            }
        }

        /*
            This function searches an item in the graph using Depth-First Search.
            Input: Character input
            Output: true if input is an item of the graph, false otherwise
        */
        bool DFS(char value)
        {
            //initialize Stack
            stack<Node*> s;

            //initialize visited list
            set<char> visited;

            //push first node
            Node* node = nodes[0];
            s.push(node);

            while (!s.empty())
            {
                node = s.top();
                s.pop();

                if (visited.find(node->value) == visited.end())
                {
                    visited.insert(node->value);
                    if (node->value == value)
                        return true;

                    //iterate through neighbors in reverse
                    for (int i = node->neighbors.size() - 1; i >= 0; i--)
                    {
                        Node* neighbor = node->neighbors[i];
                        if (neighbor->value == value)
                            return true;
                        // if neighbor is not visited, push to stack
                        if (visited.find(neighbor->value) == visited.end())
                        {
                            s.push(neighbor);
                        }
                    }
                }
            }
            return false;
        }

        /*
            This function traverses a graph using Breadth-First Search.
            Input: none
            Output: Displays traversed graph using BFS
        */
        void BFS() {
            //initialize Queue
            queue<Node*> q;

            //initialize visited list
            set<char> visited;

            //push first node
            Node* node = nodes[0];
            q.push(node);

            while (!q.empty())
            {
                node = q.front();
                q.pop();

                if (visited.find(node->value) == visited.end())
                {
                    visited.insert(node->value);
                    cout << node->value << endl;

                    //iterate through neighbors
                    for (int i = 0; i < node->neighbors.size(); i++)
                    {
                        Node* neighbor = node->neighbors[i];
                        // if neighbor is not visited, push to queue
                        if (visited.find(neighbor->value) == visited.end())
                        {
                            q.push(neighbor);
                        }
                    }
                }
            }
        }

        /*
            This function searches an item in the graph using Breadth-First Search.
            Input: Character input
            Output: true if input is an item of the graph, false otherwise
        */
        bool BFS(char value) {
            //initialize Queue
            queue<Node*> q;

            //initialize visited list
            set<char> visited;

            //push first node
            Node* node = nodes[0];
            q.push(node);

            while (!q.empty())
            {
                node = q.front();
                if (node->value == value)
                    return true;
                q.pop();

                if (visited.find(node->value) == visited.end())
                {
                    visited.insert(node->value);
                    cout << node->value << endl;

                    //iterate through neighbors
                    for (int i = 0; i < node->neighbors.size(); i++)
                    {
                        Node* neighbor = node->neighbors[i];
                        if (neighbor->value == value)
                            return true;
                        // if neighbor is not visited, push to queue
                        if (visited.find(neighbor->value) == visited.end())
                        {
                            q.push(neighbor);
                        }
                    }
                }
            }
            return false;
        }

        /*
            This function acquires a value of a vertex within the graph.
            Input: Character input
            Output: value of vertex
        */
        Node* getNode(char value)
        {
            // iterates through the vertices in the graph
            for (int i = 0; i < nodes.size(); i++)
            {
                // returns the value of the vertex
                if (nodes[i]->value == value)
                {
                    return nodes[i];
                }
            }
            return NULL;
        }

        /*
            This function connects two vertices.
            Input: 1st Character value of vertex, 2nd Character value of vertex
            Output: connected vertices
        */
        void addEdge(char value1, char value2)
        {
            Node* node1 = getNode(value1);
            Node* node2 = getNode(value2);

            // returns none if both inputs are equal to NULL
            if (node1 == NULL || node2 == NULL)
                return;

            node1->neighbors.push_back(node2);
            node2->neighbors.push_back(node1);
        }
};