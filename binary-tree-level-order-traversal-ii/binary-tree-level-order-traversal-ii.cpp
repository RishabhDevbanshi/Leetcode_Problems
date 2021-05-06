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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> arr;
        vector<vector<int>> level;
        
        if(root == NULL) return level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node)
            {
                arr.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            else
            {
                level.push_back(arr);
                arr.clear();
                
                if(q.empty()) continue;
                else q.push(NULL);
            }
        }
        
        reverse(level.begin(),level.end());
        return level;
    }
};