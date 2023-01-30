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
    int rob(TreeNode* root) {
        
        map<pair<TreeNode*,bool>,int> mp;
        
        function<int(TreeNode*,bool)> dfs = [&](TreeNode *node,bool prev){
            if(!node)
                return 0;
            
            if(mp.find({node,prev}) != mp.end())
                return mp[{node,prev}];
            
            int ans = 0;
            if(!prev)
                ans = max(node->val + dfs(node->left,true) + dfs(node->right,true),
                         dfs(node->left,false) + dfs(node->right,false));
            else
                ans = dfs(node->left,false) + dfs(node->right,false);
            return mp[{node,prev}] = ans;
        };
        
        return dfs(root,false);
    }
};