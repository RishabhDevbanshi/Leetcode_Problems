struct Node{
    // bool isEnd;
    Node *left , *right;
    Node()
    {
        // isEnd = false;
        left = right = nullptr;
    }
};

class Trie
{
    Node *trie;
    
    void insert(int num)
    {
        Node *root = trie;
        // cout<<num<<" ";
        for(int i=31;i>=0;i--)
        {
            int mask = (1<<i);
            int bit = (num>>i)&1;
            
            // cout<<bit<<" ";
            
            if(bit&1)
            {
                if(!root->right)
                    root->right = new Node();
                root = root->right;
            }
            else
            {
                if(!root->left)
                    root->left = new Node();
                root = root->left;
            }
        }
        // cout<<"\n";
        // root->isEnd = true;
    }
    
    int search(int num)
    {
        auto root = trie;
        // if(!root) root = new Node();
        int ans = 0;
        
        for(int i=31;i>=0;i--)
        {
            int mask = (1<<i);
            int bit = (num>>i)&1;
            // int ans = 0;
            
            if(bit&1)
            {
                if(!root->left)
                    root = root->right;
                else 
                {
                    root = root->left;
                    ans += mask;
                }
            }
            else
            {
                if(!root->right)
                    root = root->left;
                else 
                {
                    root = root->right;
                    ans += mask;
                }
            }
        }
        
        return ans;
    }
    
    public:
    Trie()
    {
        trie = new Node();
    }
            
    
    int maxXor(vector<int> &nums)
    {
        int ans = 0;
        
        // insert(nums.front());
        
        for(auto &val : nums)
        {
            insert(val);
            int curr = search(val);
            // cout<<curr<<" ";
            ans = max(ans,curr);
            
        }
        
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie obj;
        return obj.maxXor(nums);
    }
};