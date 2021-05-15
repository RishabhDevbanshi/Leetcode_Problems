/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> arr;
    
    void trav(TreeNode *root,int k)
    {
        if(root == NULL or k<0) return;
        if(k == 0) {arr.push_back(root->val); return;}
        
        trav(root->left,k-1);
        trav(root->right,k-1);
    }
    
    int utilAncestor(TreeNode* root,TreeNode *target,int k)
    {
        if(root == NULL) return -1;
        
        if(root == target) 
        {
            trav(root,k);
            return 0;
        }
        
        int dl = utilAncestor(root->left,target,k);
        if(dl != -1)
        {
            if(1+dl == k) arr.push_back(root->val);
            else trav(root->right,k-dl-2);
            
            return 1+dl;
        }
        
        int dr = utilAncestor(root->right,target,k);
        if(dr != -1)
        {
            if(1+dr == k) arr.push_back(root->val);
            else trav(root->left,k-dr-2);
            
            return 1+dr;
        }
        
        
        return -1;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        arr.clear();
        utilAncestor(root,target,k);
        
        return arr;
    }
};