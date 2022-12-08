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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> arr;
        
        function<void(TreeNode *)> dfs = [&](TreeNode *root){
            if(!root)
                return;
            if(!root->left and !root->right)
                arr.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        };
        
        dfs(root1);
        vector<int> a;
        swap(a,arr);
        dfs(root2);
        
        if(size(a) != size(arr))
            return false;
        return a == arr;
    }
};