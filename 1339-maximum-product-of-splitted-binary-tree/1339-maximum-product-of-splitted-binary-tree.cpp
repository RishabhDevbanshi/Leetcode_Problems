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
    int maxProduct(TreeNode* root) {
        
        long maxi = 0 , sum = 0;
        long mod = 1000000007;
        function<long(TreeNode *)> dfs = [&](TreeNode *node)->long{
            if(!node)
                return 0;
            long curr = node->val + dfs(node->left) + dfs(node->right);
            long ot = sum - curr;
            maxi = max<long>(maxi,ot * curr);
            return curr;
        };
        sum = dfs(root);
        dfs(root);
        
        return maxi%mod;
    }
};