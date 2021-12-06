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
    
    map<pair<TreeNode *,bool>,int> mp;
    
    int recur(TreeNode *root,bool isPar = false)
    {
        if(!root) return 0;
        if(!root->left and !root->right)
        {
            if(isPar) return 0;
            else return root->val;
        }
        
        if(mp.find({root,isPar}) != mp.end())
            return mp[{root,isPar}];
        
        if(isPar)
        {
            int res2 = 0;
            res2 += recur(root->left,false) + recur(root->right,false);
            return mp[{root,isPar}] = res2;
        }
        
        int res1 = root->val;
        res1 += recur(root->left,true) + recur(root->right,true);
        
        int res2 = 0;
        res2 += recur(root->left,false) + recur(root->right,false);
        
        return mp[{root,isPar}] = max(res1,res2);
    }
public:
    int rob(TreeNode* root) {
        return recur(root);
    }
};