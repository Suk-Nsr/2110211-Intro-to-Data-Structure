int depth(node *n)
{
  if (n == nullptr)
  {
    return -1;
  }
  else if (n->left_child == nullptr && n->right_sibling == nullptr)
  {
    return 0;
  }
  else if (n->left_child == nullptr)
  {
    return depth(n->right_sibling);
  }
  else if (n->right_sibling == nullptr)
  {
    return depth(n->left_child) + 1;
  }
  return std::max(depth(n->left_child) + 1, depth(n->right_sibling));
}