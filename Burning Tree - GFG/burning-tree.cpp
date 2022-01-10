// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
    
    Node* f(Node *root,map<Node*,Node*> &par,int target)
    {
        queue<Node*> q;
        q.push(root);
        Node *tar = nullptr;
        par[root] = nullptr;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node->data == target) 
            {
                tar = node;
            }
            
            if(node->left)
            {
                par[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right)
            {
                par[node->right] = node;
                q.push(node->right);
            }
        }
        
        
        return tar;
    }
    
    
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*,Node *> par;
        auto tar = f(root,par,target);
        
        int t = -1;
        queue<Node*> q;
        q.push(tar);
        map<Node*,bool> vis;
        vis[tar] = true;
        
        while(!q.empty())
        {
            t++;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                auto curr = q.front();
                q.pop();
                vis[curr] = true;
                if(curr->left and !vis[curr->left])
                {
                    q.push(curr->left);
                }
                if(curr->right and !vis[curr->right])
                {
                    q.push(curr->right);
                }
                if(par[curr] and !vis[par[curr]])
                {
                    q.push(par[curr]);
                }
            }
        }
        
        
        return t;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends