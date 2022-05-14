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
    int deepestLeavesSum(TreeNode* root) {
        
        if(!root)
            return 0;
        
        queue<TreeNode*> q;
        int res = 0;
        
        q.push(root);
        while(!q.empty())
        {
            int sz = size(q);
            vector<int> arr;
            
            res = 0;
            
            for(int i=0;i<sz;i++)
            {
                auto node = q.front();
                q.pop();
                
                res += node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        
        return res;
    }
};