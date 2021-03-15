class node
{
    public:
    node *left; //for 0
    node *right; //for 1
};

class trie
{
    node* root;
    public:
    trie()
    {
        root = new node();
    }
    
    void insert(int num)
    {
        node* temp = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            
            if(bit == 0)
            {
                if(temp->left == NULL)
                {
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else
            {
                if(temp->right == NULL)
                {
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }
    
    int max_xor_helper(int num)
    {
        node* temp = root;
        int curr = 0;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            
            if(bit == 0)
            {
                if(temp->right)
                {
                    temp = temp->right;
                    curr += (1<<i);
                }
                else temp = temp->left;
            }
            
            else
            {
                if(temp->left)
                {
                    temp = temp->left;
                    curr += (1<<i);
                }
                else temp = temp->right;
            }
        }
        
        return curr;
    }
    
    int max_xor(vector<int>& nums,int n)
    {
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            insert(nums[i]);
            int curr = max_xor_helper(nums[i]);
            ans = max(ans,curr);
        }
        
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        trie t;
        int ans = t.max_xor(nums,n);
        return ans;
    }
};