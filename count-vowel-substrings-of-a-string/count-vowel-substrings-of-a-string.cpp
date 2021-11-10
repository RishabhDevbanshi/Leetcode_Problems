class Solution {
public:
    bool check(char s)
    {
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
        {
            return true;
        }
        return false;
    }
    int find(string s,int k)
    {
        int n=s.size();
        unordered_map<char,int>mp;
        int j=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(check(s[i])==false)
            {
                j=i+1;
                mp.clear();
                
            }
            else
            {
            mp[s[i]]++;
            while(mp.size()>k)
            {
                if(--mp[s[j]]==0)
                {
                    mp.erase(s[j]);
                }
                j++;
            }
            }
            count+=i-j+1;
        }
        return count;
    }
    int countVowelSubstrings(string s)
    {
        return find(s,5)-find(s,4);
    }
};