//Time Complexity : O(height)
//Space Complexity : O(height) due to recursive stack else O(1)

BinaryTreeNode<int>* bstlca(BinaryTreeNode<int>* root,int a,int b)
{
  if(root == NULL) return NULL;

  if(a > root->data and b > root->data) return bstlca(root->right,a,b);
  else if(a < root->data and b < root->data) return bstlca(root->left,a,b);
  else return root;
}
