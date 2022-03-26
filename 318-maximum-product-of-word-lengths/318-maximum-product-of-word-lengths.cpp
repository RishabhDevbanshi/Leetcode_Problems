class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks;
        
        for(auto &word  : words)
        {
            int mask = 0;
            for(auto &ch : word)
            {
                int shift = ch - 'a';
                mask |= (1<<shift);
            }
            
            masks.push_back(mask);
        }
        
        int ans = 0;
        
        for(int i=0;i<size(masks);i++)
        {
            for(int j=i+1;j<size(masks);j++)
            {
                if((masks[i] & masks[j]) == 0)
                    ans = max<int>(ans,size(words[i]) * size(words[j]));
            }
        }
        
        return ans;
    }
};