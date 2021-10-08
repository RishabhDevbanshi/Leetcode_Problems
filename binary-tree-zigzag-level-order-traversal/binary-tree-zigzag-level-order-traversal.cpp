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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> arr;
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                arr.push_back(node->val);
            }
            if(!flag) reverse(arr.begin(),arr.end());
            flag = 1-flag;
            res.push_back(arr);
        }
        
        return res;
    }
};