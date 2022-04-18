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
    int kthSmallest(TreeNode* root, int k) {
        
        int cnt = 0;
        
        int res = -1;
        
        function<void(TreeNode *)> dfs = [&](TreeNode *node){
            if(!node)
                return;
            dfs(node->left);
            cnt++;
            if(cnt == k)
            {
                res = node->val;
            }
            
            if(cnt >= k)
                return;
            
            dfs(node->right);
        };
        
        dfs(root);
        
        return res;
    }
};