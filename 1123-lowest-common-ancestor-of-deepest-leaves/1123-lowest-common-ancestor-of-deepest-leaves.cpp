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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        map<TreeNode *,TreeNode *> par;
        queue<TreeNode *> q;
        q.push(root);
        
        par[root] = nullptr;
        
        vector<TreeNode*> last;
        
        while(!q.empty())
        {
            int sz = size(q);
            last.clear();
            for(int i=0;i<sz;i++)
            {
                auto node = q.front();
                q.pop();
                last.push_back(node);
                if(node->left)
                    q.push(node->left) , par[node->left] = node;
                if(node->right)
                    q.push(node->right) , par[node->right] = node;
            }
        }
        
        if(size(last) == 1)
            return last.front();
        
        set<TreeNode *> st;
        
        for(auto &val : last)
            q.push(val);
        
        while(!q.empty())
        {
            int sz = size(q);
            last.clear();
            for(int i=0;i<sz;i++)
            {
                auto node = q.front();
                q.pop();
                
                st.insert(node);
                
                if(node == root)
                    return root;
                
                if(st.find(par[node]) == st.end())
                    q.push(par[node]),last.push_back(par[node]) , st.insert(par[node]);
            }
            
            bool ok = true;
            
            for(int i=1;i<size(last);i++)
            {
                if(last[i] != last[i-1])
                {
                    ok = false;
                    break;
                }
            }
            
            if(ok)
                return last.front();
            
        }
        
        return root;
    }
};