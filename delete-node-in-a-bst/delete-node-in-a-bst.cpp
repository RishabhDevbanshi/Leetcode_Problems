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
    #define data val
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        
        else if(root->data > key)
        {
            root->left = deleteNode(root->left,key);
            return root;
        }
        else if(root->data < key)
        {
            root->right = deleteNode(root->right,key);
            return root;
        }
        else
        {
            if(root->left == NULL and root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left and root->right == NULL)
            {
                TreeNode* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else if(root->left == NULL and root->right)
            {
                TreeNode* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else
            {
                TreeNode* minNode = root->right;
                while(minNode->left)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = deleteNode(root->right,rightMin);
                
                return root;
            }
        }
    }
};













