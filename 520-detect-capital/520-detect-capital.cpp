class Solution {
public:
    bool detectCapitalUse(string word) {
        
        if(size(word) == 1)
            return true;
        
        bool ok = true;
        
        if(word[0]>='a' and word[0]<='z')
        {
            for(int i=1;i<size(word);i++)
            {
                if(word[i]>='a' and word[i]<='z') continue;
                else return false;
            }
        }
        else if(word[1]>='a' and word[1]<='z')
        {
            for(int i=2;i<size(word);i++)
            {
                if(word[i] >= 'a' and word[i]<='z') continue;
                else return false;
            }
        }
        else
        {
            for(auto &ch : word)
            {
                if(ch>='A' and ch<='Z') continue;
                else return false;
            }
        }
        
        return true;
    }
};