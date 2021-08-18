class Solution {
    vector<int> createLPS(string pat)
    {
        int m = pat.size();
        vector<int> lps(m);
        lps[0] = 0;
        int j=0 , i=1;
        
        while(i < m)
        {
            if(pat[i] == pat[j])
            {
                lps[i] = j+1;
                i++ , j++;
            }
            else
            {
                if(j == 0) lps[i] = 0,i++;
                else j = lps[j-1];
            }
        }
        
        return lps;
    }
public:
    int strStr(string str, string pat) {
        
        int n = str.size() , m = pat.size();
        if(m == 0) return 0;
        
        vector<int> lps = createLPS(pat);
        
        int i=0,j=0,ans = -1;
        
        while(i<n and j<m)
        {
            // cout<<i<<" "<<str[i]<<" "<<j<<" "<<pat[j]<<"\n";
            if(str[i] == pat[j]) j++ , i++;
            else 
            {
                if(j == 0) i++;
                else j = lps[j-1];
            }
            
            if(j == m) {ans = i - m; break;}
        }
        
        return ans;
    }
};