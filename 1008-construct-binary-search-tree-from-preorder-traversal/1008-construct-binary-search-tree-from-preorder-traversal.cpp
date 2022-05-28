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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        function<TreeNode*(int,int)> create = [&](int start,int end)->TreeNode*{
            
            if(start > end)
                return nullptr;
            
            TreeNode *root = new TreeNode(preorder[start]);
            
            if(start == end)
                return root;
            
            int idx = end+1;
            
            for(int i=start+1;i<=end;i++)
            {
                if(preorder[i] > preorder[start])
                {
                    idx = i;
                    break;
                }
            }
            
            root->left = create(start+1,idx-1);
            root->right = create(idx,end);
            
            
            return root;
        };
        
        auto fuck = create(0,size(preorder)-1);
        
        return fuck;
    }
};