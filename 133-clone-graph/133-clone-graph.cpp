/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    void dfs(Node *node,map<Node*,Node*> &copy,map<Node*,bool> &vis)
    {
        vis[node] = true;
        copy[node] = new Node(node->val);
        
        for(auto curr : node->neighbors)
        {
            if(vis.count(curr) == 0)
                dfs(curr,copy,vis);
        }
        
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        map<Node*,Node*> copy;
        map<Node*,bool> vis;
        
        dfs(node,copy,vis);
        
        for(auto &it : copy)
        {
            Node *curr = it.first;
            for(auto &child : curr->neighbors)
            {
                copy[curr]->neighbors.push_back(copy[child]);
            }
        }
        
        return copy[node];
        
        
    }
};