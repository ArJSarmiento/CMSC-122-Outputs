Node *INSERT(Node *root, int data, int counter)
{
    if (root == NULL)
    {
        root = new Node(data, counter);
    }
    else if (data == root->data)
    {
        root->count++;
    }
    else if (data < root->data)
    {
        root->left = INSERT(root->left, data, counter);
    }
    else
    {
        root->right = INSERT(root->right, data, counter);
    }
    return root;
}

void PREORDER(Node *root)
{
    if (root == NULL) return;
    cout << root->data << ", ";
    PREORDER(root->left);
    PREORDER(root->right);
}

void INORDER(Node *root)
{
    if (root == NULL) return;
    INORDER(root->left);
    cout << root->data << ", ";
    INORDER(root->right);
}

void POSTORDER(Node *root){
    if (root == NULL) return;
    POSTORDER(root->left);
    POSTORDER(root->right);
    cout << root->data << ", ";
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
}