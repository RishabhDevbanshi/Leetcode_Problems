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
    map<int,int> mp;
    int preIndex = 0;
    
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int start,int end)
    {
        if(start > end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        if(root == NULL) return NULL;
        
        if(start == end) return root;
        
        int index = mp[root->val];
        root->left = build(preorder,inorder,start,index-1);
        root->right = build(preorder,inorder,index+1,end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        
        return build(preorder,inorder,0,inorder.size()-1);
    }
};