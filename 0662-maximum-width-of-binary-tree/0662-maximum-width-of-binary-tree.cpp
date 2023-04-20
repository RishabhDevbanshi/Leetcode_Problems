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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left and !root->right)
            return 1;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        typedef unsigned long long ll;
        
        ll ans = 0;
        
        while(!q.empty())
        {
            ll sz = size(q);
            
            ll val = 1LL*q.back().second - 1LL*q.front().second + 1LL;
            
            ans = max(ans,val);
            
            for(int i=0;i<sz;i++)
            {
                auto p = q.front();
                q.pop();
                
                auto node = p.first;
                ll d = p.second;
                
                if(node->left)
                    q.push({node->left,d*2});
                if(node->right)
                    q.push({node->right, d*2 + 1});
            }
        }
        
        return ans;
    }
};