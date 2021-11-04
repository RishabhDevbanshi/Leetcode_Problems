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
        if(!root) return 0;
        
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        
        if(root->left and (!root->left->right and !root->left->left))
            return root->left->val + leftSum + rightSum;
        else return leftSum + rightSum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = dfs(root);
        return sum;
    }
};