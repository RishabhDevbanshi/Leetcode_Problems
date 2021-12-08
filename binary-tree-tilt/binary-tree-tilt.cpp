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
    
    int sum = 0;
    
    int findSum(TreeNode *root)
    {
        if(!root) return 0;
        
        return root->val + findSum(root->left) + findSum(root->right);
    }
    
    void recur(TreeNode *root)
    {
        if(!root) return;
        
        int left = findSum(root->left);
        int right = findSum(root->right);
        
        sum += abs(left - right);
        
        recur(root->left);
        recur(root->right);
    }
public:
    int findTilt(TreeNode* root) {
        
        sum = 0;
        
        recur(root);
        
        return sum;
    }
};