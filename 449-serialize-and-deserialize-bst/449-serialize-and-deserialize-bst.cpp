/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if(!root) return "N,";
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }
    
    TreeNode *util(queue<string> &q)
    {
        if(q.empty()) return nullptr;
        string s = q.front();
        q.pop();
        
        if(s=="N") return nullptr;
        TreeNode *root = new TreeNode(stoi(s));
        
        root->left = util(q);
        root->right = util(q);
        
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s = "";
        for(auto &ch : data)
        {
            if(ch==',') q.push(s),s="";
            else s += ch;
        }
        
        if(size(s)) q.push(s);
        
        return util(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;