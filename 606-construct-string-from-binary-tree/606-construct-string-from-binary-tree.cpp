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
    string tree2str(TreeNode* root) {
        
        string str = "";
        
        function<void(TreeNode *)> pre = [&](TreeNode *node){
            if(!node)
                return;
            
            str += "(" + to_string(node->val);
            
            if(node->left)
            {
                pre(node->left);
                pre(node->right);
            }
            else if(node->right)
            {
                str += "()";
                pre(node->right);
            }
            
            str +=")";
            
        };
        
        pre(root);
        // cout << str << " ";
        str.pop_back();
        str = str.substr(1);
        
        return str;
    }
};