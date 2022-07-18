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
    
    vector<TreeNode*> dfs(int i,int j){
         if(i>j)
            return {nullptr};
            
            vector<TreeNode*> arr;
            
            for(int k=i;k<=j;k++)
            {
                auto left = dfs(i,k-1);
                auto right = dfs(k+1,j);
                
                for(auto &val_l : left)
                {
                    for(auto &val_r : right)
                    {
                        TreeNode *root = new TreeNode(k);
                        root->left = val_l , root->right = val_r;
                        arr.push_back(root);
                    }
                }
            }
            return arr;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
    }
};