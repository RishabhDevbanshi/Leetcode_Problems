class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i=0;i<size(order);i++)
            mp[order[i]] = i;
        for(int i=0;i<size(words)-1;i++)
        {
            int a=0,b=0;
            while(a<size(words[i]) and b<size(words[i+1]) and words[i][a] == words[i+1][b])
                a++ , b++;
            if(a == size(words[i]) || b == size(words[i+1]))
            {
                if(size(words[i]) > size(words[i+1]))
                    return false;
                continue;
            }
            if(mp[words[i][a]] > mp[words[i+1][b]])
                return false;
        }
        
        
        return true;
    }
};