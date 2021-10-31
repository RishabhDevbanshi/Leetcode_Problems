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
    int dfs(TreeNode *root)
    {
        if(!root || (!root->left and !root->right)) return 0;
        int sum = dfs(root->left);
        sum += dfs(root->right);
        
        if(root->left and !root->left->left and !root->left->right)
            sum += root->left->val;
        
        return sum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root);
    }
};