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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<size(inorder);i++)
        {
            mp[inorder[i]] = i;
        }
        
        int preIdx = 0;
        
        function<TreeNode*(int,int)> dfs = [&](int left,int right)->TreeNode*{
            if(left > right)
                return nullptr;
            TreeNode *root = new TreeNode(preorder[preIdx++]);
            
            root->left = dfs(left,mp[root->val]-1);
            root->right = dfs(mp[root->val]+1,right);
            
            return root;
        };
        
        return dfs(0,size(inorder)-1);
    }
};