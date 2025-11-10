int children(node *n)
{
    if (n == NULL)
    {
        return -1;
    }
    if (n->left == NULL && n->right == NULL)
    {
        return 0;
    }
    if (n->left == NULL)
    {
        return children(n->right) + 1;
    }
    if (n->right == NULL)
    {
        return children(n->left) + 1;
    }
    return std::max(children(n->left) + 1, children(n->right) + 1);
}

void findMostImbalance(node *n, KeyT &value, int &maxImbalance)
{
    if (n == NULL)
    {
        return;
    }

    int left_height, right_height, imbalance;
    left_height = children(n->left);
    right_height = children(n->right);
    imbalance = std::abs(left_height - right_height);

    if (imbalance > maxImbalance)
    {
        maxImbalance = imbalance;
        value = n->data.first;
    }

    if (imbalance == maxImbalance && mLess(n->data.first, value))
    {
        value = n->data.first;
    }

    findMostImbalance(n->left, value, maxImbalance);
    findMostImbalance(n->right, value, maxImbalance);
}

KeyT getValueOfMostImbalanceNode()
{
    KeyT value;
    int maxImbalance = -1;
    findMostImbalance(mRoot, value, maxImbalance);
    return value;
}
