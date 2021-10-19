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
    void util(TreeNode *root,int tar,vector<int> arr,vector<vector<int>> &res)
    {
        if(!root) return;
        arr.push_back(root->val);
        tar -= root->val;
        if(!root->left and !root->right)
        {
            // for(auto val : arr) cout<<val<<" ";
            // cout<<endl;
            if(tar == 0 and arr.size() > 0) res.push_back(arr);
            return;
        }
        
        
        
        util(root->left , tar , arr, res);
        util(root->right , tar , arr , res);
        
        arr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> arr;
        util(root,targetSum,arr,res);
        return res;
    }
};