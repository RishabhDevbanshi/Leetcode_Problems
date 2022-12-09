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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        
        function<void(TreeNode*,int,int)> dfs = [&](TreeNode *node,int maxi,int mini){
            if(!node)
                return;
            if(!node->left and !node->right)
            {
                maxi = max(node->val,maxi) , mini = min(mini,node->val);
                res = max(res,maxi - mini);
                return;
            }
            
            dfs(node->right,max(maxi,node->val),min(mini,node->val));
            dfs(node->left,max(maxi,node->val),min(mini,node->val));
        };
        
        dfs(root,INT_MIN,INT_MAX);
        return res;
    }
};