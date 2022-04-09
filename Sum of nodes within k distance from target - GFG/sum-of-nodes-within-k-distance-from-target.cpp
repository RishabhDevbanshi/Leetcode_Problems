// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
    
    
public:
    int sum_at_distK(Node* root, int target, int k)
    {
        if(!root)
            return 0;
            
        Node *tar = nullptr;
        // tar = nullptr;
        map<Node*,Node*> par;
        
        par[root] == nullptr;
        
        function<void(Node *,Node *)> dfs = [&](Node *node,Node *anc){
            if(!node)
                return;
            par[node] = anc;
            
            if(node->data == target)
                tar = node;
            
            dfs(node->left,node);
            dfs(node->right,node);
        };
        
        dfs(root,nullptr);
        
        if(!tar)
            return 0;
        
        unordered_set<Node*> vis;
        
        queue<Node *> q;
        int level = 0;
        int res = 0;
        
        q.push(tar);
        
        // cout << q.size() << "\n";
        
        while(!q.empty() and level <= k)
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                auto node = q.front();
                q.pop();
                // cout << node->data << "\n";
                vis.insert(node);
                
                res += node->data;
                
                if(par[node] and vis.count(par[node]) == 0)
                    q.push(par[node]);
                if(node->left and vis.count(node->left) == 0)
                    q.push(node->left);
                if(node->right and vis.count(node->right) == 0)
                    q.push(node->right);
            }
            
            level++;
        }
        
        
        return res;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends