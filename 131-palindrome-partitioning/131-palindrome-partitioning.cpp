class Solution {
    
    bool isPal(string &str)
    {
        int start = 0 ,end = size(str)-1;
        while(start < end)
        {
            if(str[start++] != str[end--])
                return false;
        }
        
        return true;
    }
    
    void recur(string &s,int idx,vector<string> &arr,vector<vector<string>> &res)
    {
        if(idx == size(s))
        {
            res.push_back(arr);
            return;
        }
        
        string str = "";
        
        for(int i=idx;i<size(s);i++)
        {
            str += s[i];
            if(isPal(str))
            {
                arr.push_back(str);
                recur(s,i+1,arr,res);
                arr.pop_back();
            }
        }
        
    }
    
public:
    vector<vector<string>> partition(string s) {
        
        vector<string> arr;
        vector<vector<string>> res;
        
        recur(s,0,arr,res);
        
        
        return res;
        
        
    }
};