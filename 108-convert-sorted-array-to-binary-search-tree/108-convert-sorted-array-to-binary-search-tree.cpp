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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        function<TreeNode *(int,int)> dfs = [&](int start,int end)->TreeNode *{
            if(start > end)
                return nullptr;
            
            int mid = (start + end)>>1;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = dfs(start,mid-1);
            root->right = dfs(mid+1,end);
            
            
            return root;
        };
        
        return dfs(0,size(nums)-1);
    }
};