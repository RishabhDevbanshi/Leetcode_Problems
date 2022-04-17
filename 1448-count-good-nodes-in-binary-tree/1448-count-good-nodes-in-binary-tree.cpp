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
    int goodNodes(TreeNode* root) {
        
        function<int(TreeNode *,int)> dfs = [&](TreeNode *node , int maxi){
            if(!node)
                return 0;
            // cout << node->val << " " << maxi << "\n";
            if(node->val >= maxi)
            {
                // cout << node->val <<" ";
                maxi = node->val;
                return 1 + dfs(node->left , maxi) + dfs(node->right,maxi);
            }
            else
                return dfs(node->left , maxi) + dfs(node->right,maxi);
        };
        
        return dfs(root,-1e5);
    }
};