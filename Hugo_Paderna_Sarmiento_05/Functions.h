Node *INSERT(Node *root, int data, int counter);
Node *DELETE(Node *root, int data);
Node *MAX(Node *root);
Node *SEARCH(Node *root, int data);
void PREORDER(Node *root);
void INORDER(Node *root);
void POSTORDER(Node *root);
void DISPLAY(Node *root);

Node *INSERT(Node *root, int data, int counter);
void input_validation(int &input)
{
    while (!(cin >> input))
    {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
}

void input_validation_string(string &str)
{
    while (!(cin >> str))
    {
        cout << "Invalid input. Please enter a string: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
}

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

void PREORDER(Node *root)
{
    if (root == NULL) return;
    cout << root->data << ". ";
    PREORDER(root->left);
    PREORDER(root->right);
}

void INORDER(Node *root)
{
    if (root == NULL) return;
    INORDER(root->left);
    cout << root->data << ". ";
    INORDER(root->right);
}

void POSTORDER(Node *root)
{
    if (root == NULL) return;
    POSTORDER(root->left);
    POSTORDER(root->right);
    cout << root->data << ". ";
}

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