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
    bool isSymmetric(TreeNode* root) {
        
        if(!root)
            return true;
        
        function<bool(TreeNode *,TreeNode*)> recur = [&](TreeNode *a,TreeNode *b){
            if(!a and b)
                return false;
            if(a and !b)
                return false;
            if(!a and !b)
                return true;
            
            return recur(a->left,b->right) and recur(a->right,b->left) and a->val == b->val;
        };
        
        return recur(root->left,root->right);
    }
};