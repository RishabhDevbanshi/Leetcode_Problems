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
    TreeNode *first=NULL , *second = NULL;
    TreeNode *prev = NULL;
    
    void in(TreeNode *root)
    {
        if(!root)
            return;
        
        in(root->left);
        
        if(!first and prev and prev->val >= root->val)
        {
            first = prev;
        }
        
        if(first and prev->val >= root->val)
        {
            second = root;
        }
        
        prev = root;
        
        in(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        if(!root || (!root->left and !root->right))
            return ;
        in(root);
        swap(first->val,second->val);
    }
};