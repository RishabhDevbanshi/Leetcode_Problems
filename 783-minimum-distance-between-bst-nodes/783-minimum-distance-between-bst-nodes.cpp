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
    int minDiffInBST(TreeNode* root) {
        
        int prev = -1;
        
        int mini = 1e6;
        
        function<void(TreeNode *)> dfs = [&](TreeNode *node){
            if(!node)
                return;
            
            dfs(node->left);
            
            // cout << root->val << " "
            
            if(prev != -1)
            {
                // cout << root->val << " " << prev << "\n";
                mini = min(mini , node->val - prev);
            }
            
            prev = node->val;
            
            dfs(node->right);
        };
        
        dfs(root);
        
        return mini;
    }
};