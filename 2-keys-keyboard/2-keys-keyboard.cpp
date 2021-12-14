class Solution {
    map<vector<int>,int> mp;
    
    int recur(int n,int onScreen,int curr,bool lastCopy = false)
    {
        if(n == onScreen) return 0;
        if(n < onScreen) return 1e6;
        
        vector<int> key = {onScreen,curr};
        
        if(mp.find(key) != mp.end())
            return mp[key];
        
        int paste = INT_MAX;
        
        if(curr > 0)
            paste = 1 + recur(n,onScreen + curr,curr,false);
        int copy = INT_MAX;
        
        if(!lastCopy)
            copy = 1 + recur(n,onScreen,onScreen,true);
        
        return mp[key] = min(paste,copy);
    }
    
public:
    int minSteps(int n) {
        mp.clear();
        return recur(n,1,0);
    }
};