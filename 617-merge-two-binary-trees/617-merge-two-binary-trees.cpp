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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        function<TreeNode *(TreeNode *, TreeNode *)> merge = [&](TreeNode *a,TreeNode *b)->TreeNode *{
            if(!a and !b)
                return nullptr;
            if(!a)
                return b;
            if(!b)
                return a;
            TreeNode *root = new TreeNode(a->val + b->val);
            root->left = merge(a->left ,b->left);
            root->right = merge(a->right,b->right);
            
            return root;
        };
        
        return merge(root1,root2);
    }
};