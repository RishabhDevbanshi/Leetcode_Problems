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
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> freq(10);
        
        int tot=0;
        
        function<void(TreeNode *)> dfs = [&](TreeNode *node){
            if(!node)
                return;
            if(!node->left and !node->right)
            {
                freq[node->val]++;
                int cnt = 0;
                for(auto &val : freq) if(val&1) cnt++;
                tot += (cnt<2);
                freq[node->val]--;
                return;
            }
            
            freq[node->val]++;
            dfs(node->left);
            dfs(node->right);
            freq[node->val]--;
        };
        
        dfs(root);
        return tot;
    }
};