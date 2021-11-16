/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node *> q;
        q.push(root);
        root->next = NULL;
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<Node *> arr;
            
            for(int i=0;i<sz;i++)
            {
                auto node = q.front(); q.pop();
                arr.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            for(int i=0;i<arr.size()-1;i++) arr[i]->next = arr[i+1];
            arr.back()->next = NULL;
        }
        
        
        return root;
    } 
};