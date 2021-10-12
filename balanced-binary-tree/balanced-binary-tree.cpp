/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int height(TreeNode *root)
    {
        if(!root) return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
    
    bool util(TreeNode *root)
    {
        if(!root) return true;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        if(abs(lh - rh) <= 1)  return util(root->left) && util(root->right);
        
       else return false;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        return util(root);
        
    }
};