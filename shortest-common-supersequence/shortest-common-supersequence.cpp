class Solution {
    string recur(string &s1,string &s2,int n1,int n2)
    {
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        string lcs = "";
        while(n1>0 and n2>0)
        {
            if(s1[n1-1] == s2[n2-1])
                lcs.push_back(s1[n1-1]) , n1--, n2--;
            else if(dp[n1-1][n2] > dp[n1][n2-1])
                n1--;
            else
                n2--;
        }
        
        reverse(lcs.begin(),lcs.end());
        
        return lcs;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size() , n2 = str2.size();
        
        string lcs = recur(str1,str2,n1,n2);
        cout<<lcs;
        
        int i=0 , j=0;
        string str = "";
        
        for(char ch : lcs)
        {
            while(str1[i] != ch)
                str += str1[i++];
            while(str2[j] != ch)
                str += str2[j++];
            
            str.push_back(ch);
            ++i , ++j;
        }
        
        str += str1.substr(i) + str2.substr(j);
        
        return str;
    }
};