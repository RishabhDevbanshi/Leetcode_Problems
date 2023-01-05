class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> mp;
        for(auto &val : tasks)
            mp[val]++;
        
        int rounds = 0;
        
        for(auto it : mp)
        {
            int tmp = it.second;
            int th = tmp / 3;
            
            tmp -= th * 3;
            if(tmp % 2 != 0)
            {
                th--;
                tmp = min(3 + tmp, it.second);
            }
            
            int tw = tmp / 2;
            tmp -= 2*tw;
            
            if(tmp)
                return -1;
            
            rounds += th + tw;
            
            
        }
        
        return rounds;
    }
};