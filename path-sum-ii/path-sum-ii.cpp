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
public:
    void util(TreeNode* root,int targetSum,vector<vector<int>> &arr,vector<int> helper)
    {
        if(root and !root->left and !root->right and targetSum == root->val)
        {
            helper.push_back(root->val);
            arr.push_back(helper);
            return;
        }
        
        if(root == NULL) return;
        
        helper.push_back(root->val);
        int val = root->val;
        util(root->left,targetSum-val,arr,helper);
        util(root->right,targetSum-val,arr,helper);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> arr;
        vector<int> helper;
        util(root,targetSum,arr,helper);
        return arr;
    }
};