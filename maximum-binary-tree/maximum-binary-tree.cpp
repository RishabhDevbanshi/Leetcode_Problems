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
    int max(vector<int> &nums,int l,int r)
    {
        int ans = -1,idx=0;
        for(int i=l;i<=r;i++) 
        {
            if(nums[i] > ans)
            {
                ans = nums[i];
                idx = i;
            }
        }
        return idx;
    }
    
    TreeNode* recur(vector<int> &nums,int l,int r)
    {
        if(l > r) return NULL;
        int me = max(nums,l,r);
        TreeNode *root = new TreeNode(nums[me]);
        if(l == r) return root;
        root->left = recur(nums,l,me-1);
        root->right = recur(nums,me+1,r);
        
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recur(nums,0,nums.size()-1);
    }
};