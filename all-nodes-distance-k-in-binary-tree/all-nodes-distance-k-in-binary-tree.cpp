/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0)
        {
            vector<int> arr;
            arr.push_back(target->val);
            return arr;
        }
        unordered_map<TreeNode* , TreeNode*> par;
        queue<TreeNode*> q;
        q.push(root);
        par[root] = NULL;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                {
                    par[node->left] = node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    par[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        unordered_map<TreeNode*,bool> vis;
        vector<int> res;
        int lvl = 0;
        q.push(target);
        vis[target] = true;
        while(!q.empty())
        {
            vector<int> arr;
            lvl++;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->left and !vis[node->left])
                {
                    arr.push_back(node->left->val);
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right and !vis[node->right])
                {
                    arr.push_back(node->right->val);
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(par[node] and !vis[par[node]])
                {
                    arr.push_back(par[node]->val);
                    q.push(par[node]);
                    vis[par[node]] = true;
                }
            }
            if(lvl == k) return arr;
        }
        return {};
    }
};





