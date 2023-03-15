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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool ok=false;
        q.push(root);
        while(!q.empty())
        {
            int sz=size(q);
            // bool ok = false;
            for(int i=0;i<sz;i++)
            {
                auto node=q.front();
                q.pop();
                if(!node->left and !node->right)
                {
                    ok=true;
                    continue;
                }
                else if(ok)
                    return false;
                if(node->left and node->right)
                {
                    q.push(node->left);
                    q.push(node->right);
                }
                else if(!node->left and node->right)
                {
                    return false;
                }
                else if(node->left and !node->right)
                {
                    q.push(node->left);
                    ok=true;
                }
            }
        }
        
        return true;
    }
};