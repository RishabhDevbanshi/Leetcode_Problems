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
    void inorder(TreeNode* root,vector<TreeNode *> &arr)
    {
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root);
        inorder(root->right,arr);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> arr;
        inorder(root,arr);
        if(arr.size() <=1) return;
        int n = arr.size();
        vector<TreeNode *> temp = arr;
        sort(temp.begin(),temp.end(),[](TreeNode *a,TreeNode *b){
            return a->val < b->val;
        });
        TreeNode *x = NULL,*y = NULL;
        for(int i=0;i<n;i++)
        {
            if(arr[i] != temp[i])
            {
                if(!x) x = arr[i];
                else y = arr[i];
            }
        }
        swap(x->val,y->val);
    }
};




