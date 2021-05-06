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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> arr;
        if(root == NULL) return arr;
        
        queue<TreeNode*> q;
        double sum = 0, count=0;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node)
            {
                sum += node->val;
                count++;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            else
            {
                double avg = sum/count;
                sum = count = 0;
                
                arr.push_back(avg);
                if(q.empty()) continue;
                else q.push(NULL);
            }
        }
        
        
        return arr;
    }
};