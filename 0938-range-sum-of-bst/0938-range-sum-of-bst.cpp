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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int tot=0;
        
        function<void(TreeNode *)> dfs = [&](TreeNode *node){
            if(!node)
                return;
            if(node->val < low)
            {
                dfs(node->right);
            }
            else if(node->val > high)
            {
                dfs(node->left);
            }
            else
            {
                tot += node->val;
                dfs(node->left);
                dfs(node->right);
            }
        };
        
        dfs(root);
        
        return tot;
    }
};