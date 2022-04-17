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
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode *head = new TreeNode(0);
        TreeNode *tail = head;
        
        function<void(TreeNode *)> in = [&](TreeNode *node){
            
            if(!node)
                return;
            in(node->left);
            
            tail->right = new TreeNode(node->val);
            tail = tail->right;
            
            in(node->right);
        };
        
        in(root);
        
        return head->right;
    }
};