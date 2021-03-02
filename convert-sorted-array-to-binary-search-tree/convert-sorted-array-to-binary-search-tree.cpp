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
    TreeNode* helper(vector<int>& arr,int start,int end)
    {
        if(start > end) return NULL;

        int mid = (start + end)/2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = helper(arr,start,mid-1);
        node->right = helper(arr,mid+1,end);

        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int sz = arr.size();
	    return helper(arr,0,sz-1);
    }
};