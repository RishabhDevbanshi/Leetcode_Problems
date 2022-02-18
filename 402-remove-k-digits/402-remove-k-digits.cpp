class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(auto &ch : num)
        {
            while(size(ans) and ans.back() > ch and k)
                ans.pop_back() , k--;
            
            if(size(ans) || ch != '0')
                ans.push_back(ch);
        } 
        
        
        while(size(ans) and k--)
            ans.pop_back();
        
        
        return ans == "" ? "0" : ans;
    }
};