KeyT getValueOfMostImbalanceNode()
{
    KeyT value;
    int maxImbalance = -1;
    findMostImbalance(this->mRoot, value, maxImbalance);
    return value;
}

int findDepth(node *n)
{
    if (n == nullptr)
    {
        return -1;
    }
    return std::max(findDepth(n->left) + 1, findDepth(n->right) + 1);
}

void findMostImbalance(node *n, KeyT &value, int &maxImbalance)
{
    if (n == nullptr)
    {
        return;
    }

    int leftHeight = findDepth(n->left);
    int rightHeight = findDepth(n->right);
    int imbalanceValue = std::abs(leftHeight - rightHeight);

    if (imbalanceValue > maxImbalance)
    {
        maxImbalance = imbalanceValue;
        value = n->data.first;
    }

    findMostImbalance(n->left, value, maxImbalance);
    findMostImbalance(n->right, value, maxImbalance);
}