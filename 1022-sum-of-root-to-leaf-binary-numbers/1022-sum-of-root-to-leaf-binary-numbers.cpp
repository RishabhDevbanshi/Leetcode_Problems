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
    
    int ans = 0;
    
    int inDec(string &bin)
    {
        int res = 0;
        int p = size(bin)-1;
        
        for(auto &ch : bin)
        {
            int bit = ch - '0';
            if(bit)
            {
                res += (1<<p);
            }
            p--;
        }
        
        return res;
        
    }
    
    void dfs(TreeNode *root,string bin)
    {
        if(!root)
        {
            // cout<<bin<<"\n";
            return;
        }
        
        if(!root->left and !root->right)
        {
            bin += ('0' + root->val);
            ans += inDec(bin);
            return;
        }
        
        char ch = '0' + root->val;
        bin += ch;
        
        dfs(root->left,bin);
        dfs(root->right,bin);
        
        
    }
    
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root,"");
        
        return ans;
    }
};