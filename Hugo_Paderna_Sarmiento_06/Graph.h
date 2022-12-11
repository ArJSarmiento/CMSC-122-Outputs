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
        void addNode(char value)
        {
            Node* node = new Node(value);
            nodes.push_back(node);
        }

        Graph(char *values, int size)
        {
            for (int i = 0; i < size; i++)
            {
                addNode(values[i]);
            }
        }

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

                    //itereate through neighbors reverse
                    for (int i = node->neighbors.size() - 1; i >= 0; i--)
                    {
                        Node* neighbor = node->neighbors[i];
                        if (visited.find(neighbor->value) == visited.end())
                        {
                            s.push(neighbor);
                        }
                    }
                }
            }
        }

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

                    //itereate through neighbors reverse
                    for (int i = node->neighbors.size() - 1; i >= 0; i--)
                    {
                        Node* neighbor = node->neighbors[i];
                        if (neighbor->value == value)
                            return true;
                        if (visited.find(neighbor->value) == visited.end())
                        {
                            s.push(neighbor);
                        }
                    }
                }
            }
            return false;
        }

        // Traverse the graph using breadth-first search
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

                    //itereate through neighbors
                    for (int i = node->neighbors.size() - 1; i >= 0; i--)
                    {
                        Node* neighbor = node->neighbors[i];
                        if (visited.find(neighbor->value) == visited.end())
                        {
                            q.push(neighbor);
                        }
                    }
                }
            }
        }

        // Traverse the graph using breadth-first search
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

                    //itereate through neighbors
                    for (int i = node->neighbors.size() - 1; i >= 0; i--)
                    {
                        Node* neighbor = node->neighbors[i];
                        if (neighbor->value == value)
                            return true;
                        if (visited.find(neighbor->value) == visited.end())
                        {
                            q.push(neighbor);
                        }
                    }
                }
            }
            return false;
        }

        Node* getNode(char value)
        {
            for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i]->value == value)
                {
                    return nodes[i];
                }
            }
            return NULL;
        }

        void addEdge(char value1, char value2)
        {
            Node* node1 = getNode(value1);
            Node* node2 = getNode(value2);

            if (node1 == NULL || node2 == NULL)
                return;

            node1->neighbors.push_back(node2);
            node2->neighbors.push_back(node1);
        }
};