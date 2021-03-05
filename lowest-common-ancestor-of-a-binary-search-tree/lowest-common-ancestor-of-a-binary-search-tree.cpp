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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int n1 = p->val, n2 = q->val;
        while (root != NULL) 
        { 
            if (root->val > n1 && root->val > n2) 
            root = root->left; 
            
            else if (root->val < n1 && root->val < n2) 
            root = root->right; 

            else break; 
        } 
        return root;
        }
};