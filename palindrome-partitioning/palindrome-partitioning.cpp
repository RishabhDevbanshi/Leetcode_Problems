class Solution {
    bool isPal(string str,int start,int end)
    {
        while(start < end)
        {
            if(str[start++] != str[end--])
                return false;
        }
        
        return true;
    }
    
    void helper(string s,int ind,vector<string> &arr,vector<vector<string>> &res)
    {
        if(ind == s.size())
        {
            res.push_back(arr);
            return;
        }
        
        for(int i=ind;i<s.size();i++)
        {
            if(isPal(s,ind,i))
            {
                arr.push_back(s.substr(ind,i-ind+1));
                helper(s,i+1,arr,res);
                arr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> arr;
        
        helper(s,0,arr,res);
        
        return res;
    }
};