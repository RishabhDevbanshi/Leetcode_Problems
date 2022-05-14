/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        queue<Node *> q;
        q.push(root);
        vector<vector<int>> arr;
        
        while(!q.empty())
        {
            int sz = size(q);
            vector<int> tmp;
            for(int i=0;i<sz;i++)
            {
                auto node = q.front();
                q.pop();
                
                tmp.push_back(node->val);
                
                for(auto &child : node->children)
                {
                    q.push(child);
                }
            }
            
            arr.push_back(tmp);
        }
        
        
        return arr;
    }
};