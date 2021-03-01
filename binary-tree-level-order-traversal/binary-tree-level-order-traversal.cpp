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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> pendingNode;
        pendingNode.push(root);
        pendingNode.push(NULL);
        vector<int> arr;
        vector<vector<int>> level;
        
        if(root == NULL) return level;

        while(!pendingNode.empty())
        {
            TreeNode* node = pendingNode.front();
            pendingNode.pop();
            if(node)
            {
                arr.push_back(node->val);
                if(node->left) pendingNode.push(node->left);
                if(node->right) pendingNode.push(node->right);
            }
            else
            {
                level.push_back(arr);
                arr.clear();
                if(pendingNode.empty()) continue;
                else
                {
                    // cout<<"\n";
                    pendingNode.push(NULL);
                }
            }
        }

        return level;
    }
};