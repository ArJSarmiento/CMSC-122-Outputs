/*
    This Script declares all the necessary functions
*/

// Define function prototypes
Node *INSERT(Node *root, int data, int counter);
Node *DELETE(Node *root, int data);
Node *MAX(Node *root);
Node *SEARCH(Node *root, int data);
void PREORDER(Node *root);
void INORDER(Node *root);
void POSTORDER(Node *root);
void DISPLAY(Node *root);
Node *FINDMINIMUM(Node *root);
Node *SUCCESSOR(Node *root, int data);
Node *PREDECESSOR(Node *root, int data);

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
    This function validates string inputs. Gets the entire line of input. 
    Input: pointer of input string
    Output: none
*/
void input_validation_string(string &str)
{
    cin.ignore();
    getline(cin, str);
}

/*
    This function inserts a node to the BST
    Input: pointer of root node, data to be inserted
    Output: pointer of new root node
*/
Node *INSERT(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
    }
    else if (data == root->data)
    {
        root->count++;
    }
    else if (data < root->data)
    {
        root->left = INSERT(root->left, data);
    }
    else
    {
        root->right = INSERT(root->right, data);
    }
    return root;
}

Node *DELETE(Node *root, int data)
{
    // Search root node to be deleted
    if (root == NULL) 
        return root;

    else if (data < root->data) 
        root->left = DELETE(root->left, data);

    else if (data > root->data) 
        root->right = DELETE(root->right, data);

    // Leaf node case
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        root = NULL;
    }

    // Case of one child
    else if (root->left == NULL) // left side is empty
    {
        struct Node *temp = root;
        root = root->right;
        delete temp;
    }
    else if (root->right == NULL) // right side is empty
    {
        struct Node *temp = root;
        root = root->left;
        delete temp;
    }
    
    // Case of two children
    else 
    {
        struct Node *temp = MAX(root->left);
        root->data = temp->data;
        root->left = DELETE(root->left, temp->data);
    }

    return root;
}

Node *MAX(Node *root)
{
    if (root == NULL)
        return root;
        
    else if (root->right == NULL)
        return root;

    return MAX(root->right);
}

Node *SEARCH(Node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;

    if (data > root->data)
        return SEARCH(root->right, data);
    
    return SEARCH(root->left, data);
}

/*
    This function prints the preorder traversal of the tree
    Input: pointer of root node
    Output: none
*/
void PREORDER(Node *root)
{
    if (root == NULL) return;
    cout << root->data << ". ";
    PREORDER(root->left);
    PREORDER(root->right);
}

/*
    This function prints the inorder traversal of the tree
    Input: pointer of root node
    Output: none
*/
void INORDER(Node *root)
{
    if (root == NULL) return;
    INORDER(root->left);
    cout << root->data << ". ";
    INORDER(root->right);
}

/*
    This function prints the postorder traversal of the tree
    Input: pointer of root node
    Output: none
*/
void POSTORDER(Node *root)
{
    if (root == NULL) return;
    POSTORDER(root->left);
    POSTORDER(root->right);
    cout << root->data << ". ";
}

/*
    This function prints the tree in Preorder, Inorder, and Postorder 
    Input: pointer of root node
    Output: none
*/
void DISPLAY(Node *root)
{
    if (root == NULL) return;
    cout << "\nPre-order: \n";
    PREORDER(root);
    cout << "\nIn-order: \n";
    INORDER(root);
    cout << "\nPost-order: \n";
    POSTORDER(root);
    cout << endl;
}

Node *MIN(Node *root)
{
    if (root == NULL) return root;
    else if (root->left == NULL)
        return root;
    return MIN(root->left);
}

Node *SUCCESSOR(Node *root, int data)
{
    //Search the tree if the item exists
    Node *current = SEARCH(root, data);
    if(current == NULL) return NULL;

    //Case when Node has right subtree
    if(current->right != NULL)
        return MIN(current->right);

    //Case when Node has no right subtree
    else
    {
        Node *successor = NULL;
        Node *ancestor = root;
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

Node *PREDECESSOR(Node *root, int data)
{
    //Search the tree if the item exists
    Node *current = SEARCH(root, data);
    if(current == NULL) return NULL;

    //Case when Node has left subtree
    if(current->left != NULL)
        return MAX(current->left);

    //Case when Node has no left subtree
    else
    {
        Node *predecessor = NULL;
        Node *ancestor = root;
        while(ancestor != current)
        {
            if(current->data > ancestor->data)
            {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else
                ancestor = ancestor->left;
        }
        return predecessor;
    }
}