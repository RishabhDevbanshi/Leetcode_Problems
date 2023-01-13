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
    int longestUnivaluePath(TreeNode* root) {
        
        if(!root)
            return 0;
        
        function<pair<int,int>(TreeNode *)> dfs = [&](TreeNode *node)->pair<int,int>{
            if(!node)
                return {0,0};
            auto left = dfs(node->left) , right = dfs(node->right);
            
            int op1 = node->left and node->val == node->left->val ? left.first : 0;
            int op2 = node->right and node->val == node->right->val ? right.first : 0;
            
            
            int x = 1 + max(op1,op2);
            int y = max({1+op1+op2,left.second,right.second});
            
            // cout << (node->val) << " " << x << " " << y << "\n";
            
            return {1+max(op1,op2),max({1+op1+op2,left.second,right.second})};
        };
        
        
        int res = dfs(root).second;
        return res-1 ? res-1: 0;
    }
};