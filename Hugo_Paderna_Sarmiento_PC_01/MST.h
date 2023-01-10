/*
    Class definition for MST
*/
class MST
{
    // Node struct for representing a node in the MST
    class Node {
        public:
            char value;
            vector<Node*> neighbors;

            Node(char val) {
                value = val;
            }
    };

    // List for storing all of the nodes in the MST 
    vector<Node*> nodes;
};