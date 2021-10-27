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
    void recur(TreeNode *root,vector<string> &res,vector<int> &path)
    {
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            string str = "";
            for(int i=0;i<path.size()-1;i++) {
                str += to_string(path[i]);
                str += "->";
            }
            str += to_string(path.back());
            res.push_back(str);
            path.pop_back();
            return;
        }
        
        recur(root->left,res,path);
        recur(root->right,res,path);
        
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        recur(root,res,path);
        return res;
    }
};