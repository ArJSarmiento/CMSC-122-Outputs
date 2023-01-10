/*
    Class definition for Graph
*/
class Graph
{
    private:
        // Edge struct for representing an edge in the graph
        class Edge {
            public:
                int source;
                int destination;
                int weight;

                Edge(int src, int dest, int wgt) {
                    source = src;
                    destination = dest;
                    weight = wgt;
                }
        };

        // Node struct for representing a node in the graph
        class Node {
            public:
                int value;
                vector<Edge*> edges;

                Node(int val) {
                    value = val;
                }
        };

        // List for storing all of the nodes in the graph
        vector<Node*> nodes;
        Node* startNode;

    public:

        /*
            This function adds a node to the graph.
            Input: value of node
            Output: node object 
        */

        Node* addNode(int value)
        {
            Node* node = new Node(value);
            nodes.push_back(node);
            return node;
        }

        /*
            This function acquires a value of a vertex within the graph.
            Input: intacter input
            Output: value of vertex
        */
        Node* getNode(int value)
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

            // adds the node if none
            return addNode(value);
        }

        /*
            This function connects two vertices.
            Input: 1st intacter value of vertex, 2nd intacter value of vertex
            Output: connected vertices
        */
        void addEdge(int value1, int value2, int weight)
        {
            Node* node1 = getNode(value1);
            Node* node2 = getNode(value2);
            
            // creates an edge between the two vertices
            Edge* edge1 = new Edge(node1->value, node2->value, weight);
            Edge* edge2 = new Edge(node2->value, node1->value, weight);

            // adds the edge to the vertices
            node1->edges.push_back(edge1);
            node2->edges.push_back(edge2);
        }


        void setStartingNode(int value)
        {
            startNode = getNode(value);
        }
};