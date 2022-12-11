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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        
        function<int(TreeNode *)> dfs = [&](TreeNode *node){
            if(!node)
                return 0;
            int left = dfs(node->left) , right = dfs(node->right);
            int to_return = max({node->val,node->val + left,node->val + right});
            ans = max({ans,node->val + left + right,to_return});
            return to_return;
        };
        
        dfs(root);
        
        return ans;
    }
};