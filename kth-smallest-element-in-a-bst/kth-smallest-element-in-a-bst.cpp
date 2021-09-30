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
    int kthSmallest(TreeNode* A, int k) {
        stack<TreeNode*> st;
        int cnt = 0;
        TreeNode* temp = A; 

        while(!st.empty() || temp)
        {
            while(temp)
            {
                st.push(temp);
                temp = temp->left;
            }

            temp = st.top();
            cnt++;
            
            if(cnt == k) 
                return temp->val;
            // cout<<st.top()->val<<" ";
            st.pop();

            temp = temp->right;
        }

        // cout<<"\n";
        return 0;
    }
};