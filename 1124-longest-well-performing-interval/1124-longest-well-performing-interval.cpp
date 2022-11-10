class Solution {
public:
    int longestWPI(vector<int>& hours) {
        for(auto &hour : hours)
            hour = hour > 8 ? 1 : -1;
        unordered_map<int,int> mp;
        
        int sum=0,cnt=0;
        
        for(int i=0;i<size(hours);++i)
        {
            sum += hours[i];
            
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
            
            if(sum > 0)
                cnt = max(cnt,i+1);
            if(mp.find(sum-1) != mp.end())
                cnt = max(cnt,i-mp[sum-1]);
        }
        
        return cnt;
    }
};