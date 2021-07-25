class Solution {
    string substring(string s,int i,int x)
    {
        string res = "";
        for(int j=i;j<=x;j++) res += s[j];
        return res;
    }
    
    bool recur(string s,set<string> &st,int i,int dp[])
    {
        if(i == s.size()) return dp[i] = true;
        
        if(dp[i] != -1) return dp[i];
        
        for(int x=i;x<s.size();x++)
        {
            string sub = substring(s,i,x);
            // cout<<sub<<" ";
            bool flag = false;
            if(st.find(sub) != st.end())
            {
                flag = recur(s,st,x+1,dp);
            }
            if(flag) return dp[i] = flag;
        }
        
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(),wordDict.end());
        int dp[s.size() + 1];
        memset(dp,-1,sizeof(dp));
        return recur(s,st,0,dp);
        
    }
};