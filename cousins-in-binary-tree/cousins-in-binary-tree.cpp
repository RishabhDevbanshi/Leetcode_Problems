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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        queue<pair<TreeNode*,int>> q;
        q.push({root,-1});
        while(!q.empty())
        {
            int a=-2,b=-2;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                auto info = q.front(); q.pop();
                TreeNode *node = info.first;
                if(node->val == x) a = info.second;
                else if(node->val == y) b = info.second;
                
                if(node->left) q.push({node->left,node->val});
                if(node->right) q.push({node->right,node->val});
            }
            
            if(a!=-2 and b!=-2)
            {
                return (a!=b);
            }
            else if(a!=-2 or b!=-2) return false;
        }
        
        return false;
    }
};








