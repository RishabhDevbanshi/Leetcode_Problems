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
    
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> res;
        if(!root) return res;
        stack<pair<TreeNode *,int>> st;
        st.push({root,0});
        while(!st.empty())
        {
            auto p = st.top(); st.pop();
            auto node = p.first; int cnt = p.second;
            // cout<<node->val<<" "<<cnt<<"\n";
            if(cnt<2) st.push({node,cnt+1});
            if(cnt == 0) res.push_back(node->val);
            else if(cnt == 1) {if(node->left) st.push({node->left,0});}
            else if(cnt == 2){ if(node->right) st.push({node->right,0});}
        }
        
        return res;
    }
};