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
    void inorder(TreeNode* root,vector<int>& arr)
    {
        if(root == NULL) return;
        
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root,nodes);
        for(int i=1;i<nodes.size();i++)
        {
            if(nodes[i-1] >= nodes[i]) return false;
        }
        return true;
    }
};