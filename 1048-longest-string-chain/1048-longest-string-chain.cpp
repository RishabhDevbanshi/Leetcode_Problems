class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        unordered_set<string> st(words.begin(),words.end());
        
        unordered_map<string,int> dp;
        
        function<int(string &)> fun = [&](string &word)->int{
            
            if(dp.find(word) != dp.end())
                return dp[word];
            
            int maxi = 1;
            for(int i=0;i<size(word);i++)
            {
                string tmp = word.substr(0,i);
                if(i+1 < size(word))
                {
                    tmp += word.substr(i+1);
                }
                
                if(st.find(tmp) != st.end())
                    maxi = max(maxi,fun(tmp)+1);
            }
            
            
            return dp[word] = maxi;
        };
        
        int maxi = 0;
        for(auto &word : words)
            maxi = max(maxi,fun(word));
        
        return maxi;
    }
};