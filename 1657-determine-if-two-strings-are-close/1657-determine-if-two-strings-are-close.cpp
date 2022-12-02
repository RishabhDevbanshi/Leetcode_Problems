class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a(26) , b(26);
        
        for(auto &ch : word1)
            a[ch - 'a']++;
        for(auto &ch : word2)
            b[ch - 'a']++;
        
        for(int i=0;i<26;i++)
        {
            if(a[i] == b[i])
                continue;
            if((a[i] and b[i] == 0) or (b[i] and a[i] == 0))
                return false;
            
            bool ok = true;
            
            for(int j=i+1;j<26;j++)
            {
                if(a[j] == 0)
                    continue;
                if(a[j] == b[i])
                    swap(a[i],a[j]) , ok = false;
            }
            
            if(ok)
                return false;
                
        }
        
        return true;
    }
};

// aa bbb c

// 2 3 1

// a bb ccc

// 1 2 3