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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> lol,arr;
        if(root == NULL) return lol;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            
            if(node)
            {
                arr.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            else
            {
                int val = arr.back();
                lol.push_back(val);
                arr.clear();
                
                if(!q.empty()) q.push(NULL);
            }
        }
        
        return lol;
    }
};













