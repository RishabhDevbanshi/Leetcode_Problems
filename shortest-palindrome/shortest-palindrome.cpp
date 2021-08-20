class Solution {
    int computeLPS(string s)
    {
        int n = s.size();
        int lps[n];
        lps[0] = 0;
        int j=0,i=1;
        
        while(i < n)
        {
            if(s[i] == s[j])
            {
                lps[i] = j+1;
                i++, j++;
            }
            else
            {
                if(j == 0) lps[i] = 0 ,i++;
                else j = lps[j-1];
            }
        }
        
        return lps[n-1];
    }
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        
        string concat = s + "$" + rev;
        
        int val = computeLPS(concat);
        // cout<<val<<"\n";
        
        rev = "";
        
        for(int i=val;i<s.size();i++) rev += s[i];
        
        // cout<<rev<<"\n";
        
        reverse(rev.begin(),rev.end());
        
        return (rev + s);
        
    }
};