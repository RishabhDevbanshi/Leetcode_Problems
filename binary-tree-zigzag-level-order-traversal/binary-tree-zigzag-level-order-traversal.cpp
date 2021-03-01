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
        vector<int> arr;
        vector<vector<int>> level;
        
        if(root == NULL) return level;
        queue<TreeNode*> pendingNode;
        pendingNode.push(root);
        pendingNode.push(NULL);
        arr.push_back(root->val);
        level.push_back(arr);
        arr.clear();
        
        while(!pendingNode.empty())
        {
            TreeNode* node = pendingNode.front();
            pendingNode.pop();
            
            if(node)
            {
                if(node->left)
                {
                    arr.push_back(node->left->val);
                    pendingNode.push(node->left);
                }
                if(node->right)
                {
                    arr.push_back(node->right->val);
                    pendingNode.push(node->right);
                }
            }
            else
            {
                if(pendingNode.empty()) break;
                else
                {
                    pendingNode.push(NULL);
                    int sz = level.size();
                    if(sz%2 == 0)
                    {
                        level.push_back(arr);
                    }
                    else
                    {
                        reverse(arr.begin(),arr.end());
                        level.push_back(arr);
                    }
                    arr.clear();
                }
            }
        }
        return  level;
    }
};