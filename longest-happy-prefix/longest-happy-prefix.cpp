class Solution {
public:
    string longestPrefix(string str) {
        int n = str.size();
        int lps[n];
        lps[0] = 0;
        int i=1, len = 0;
        while(i < n)
        {
            if(str[i] == str[len])
            {
                lps[i] = len + 1;
                len++;
                i++;
            }
            else 
            {
                if(len == 0) {lps[i] = 0; i++;}
                else len = lps[len - 1];
            }
        }
        
        string ans = "";
        i = n-1;
        
        for(int i=0;i<n;i++) cout<<lps[i]<<" ";
        cout<<"\n";
        
        while(lps[n-1]--)
        {
            ans += str[i];
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};