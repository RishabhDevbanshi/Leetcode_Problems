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
class BSTIterator {
    stack<int> st;
    void preorder(TreeNode *root)
    {
        if(!root) return;
        preorder(root->right);
        st.push(root->val);
        preorder(root->left);
    }
public:
    BSTIterator(TreeNode* root) {
        preorder(root);
    }
    
    int next() {
        int val = st.top(); st.pop();
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */