class Solution {
    string mp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void recur(string str,string ans,vector<string> &arr)
    {
        if(str.size() == 0) 
        {
            if(ans != "") arr.push_back(ans);
            return;
        }
        
        string ros = str.substr(1);
        
        int idx = str[0] - '0';
        
        for(char ch : mp[idx])
        {
            recur(ros,ans + ch,arr);
        }
        
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> arr;
        recur(digits,"",arr);
        return arr;
    }
};