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
    long long sum;
    void recur(TreeNode *root,long long num)
    {
        if(!root) return;
        num *= 10;
        num += root->val;
        if(!root->left and !root->right) {
            sum += num;
            return  ;
        }
        
        if(root->left) recur(root->left,num);
        if(root->right) recur(root->right , num);
    }
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        long long num = 0;
        recur(root,num);
        return sum;
    }
};