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
    
    int res = 0;
    
    vector<int> dfs(TreeNode *root)
    {
        if(!root) return {INT_MAX,INT_MIN};
        if(!root->left and !root->right) return {root->val,root->val};
        
        vector<int> a = dfs(root->left);
        vector<int> b = dfs(root->right);
        
        int mn = min(a[0],b[0]) , mx = max(a[1],b[1]);
        
        res = max({res,abs(mn-root->val),abs(mx - root->val)});
        
        mn = min(root->val,mn) , mx = max(root->val,mx);
        
        
        return {mn,mx};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return res;
    }
};