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
    
    void dfs(TreeNode *root,int val)
    {
        if(!root) return;
        if(root->val < val)
        {
            if(root->right) dfs(root->right,val);
            else {root->right = new TreeNode(val); return;}
        }
        else
        {
            if(root->left) dfs(root->left,val);
            else {root->left = new TreeNode(val); return;}
        }
    }
    
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        dfs(root,val);
        return root;
    }
};