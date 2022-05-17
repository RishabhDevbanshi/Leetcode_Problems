/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        function<TreeNode *(TreeNode *)> dfs = [&](TreeNode *node)->TreeNode *{
            if(!node)
                return nullptr;
            
            TreeNode *left = dfs(node->left);
            if(left)
                return left;
            TreeNode *right = dfs(node->right);
            if(right)
                return right;
            
            return node->val == target->val ? node : nullptr;
        };    
        
        return dfs(cloned);
    }
};