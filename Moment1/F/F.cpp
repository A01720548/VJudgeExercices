bool isSubTreeLesser(Node *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data < value &&
        isSubTreeLesser(root->left, value) &&
        isSubTreeLesser(root->right, value))
        return true;
    else
        return false;
}
bool isSubTreeGreater(Node *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data > value &&
        isSubTreeGreater(root->left, value) &&
        isSubTreeGreater(root->right, value))
        return true;
    else
        return false;
}
bool checkBST(Node *root)
{
    if (root == NULL)
        return true;
    if (isSubTreeLesser(root->left, root->data) &&
        isSubTreeGreater(root->right, root->data) &&
        checkBST(root->left) &&
        checkBST(root->right))
        return true;
    else
        return false;
}
