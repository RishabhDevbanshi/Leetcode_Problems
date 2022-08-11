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
    bool isValidBST(TreeNode* root) {
        int prev = -1; bool ok = false;
        stack<TreeNode*> st;
        
        auto tmp = root;
        while(tmp)
            st.push(tmp) , tmp = tmp->left;
        
        while(!st.empty())
        {
            auto node = st.top(); st.pop();
            if(!ok) ok = true , prev = node->val;
            else if(node->val <= prev) return false;
            prev = node->val;
            if(node->right)
            {
                node = node->right;
                while(node)
                    st.push(node) , node = node->left;
            }
        }
        
        return true;
    }
};