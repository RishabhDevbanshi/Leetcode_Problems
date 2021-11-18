#define ll long long

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        unordered_map<ll,int> mp;
        pq.push(1);
        mp[1] = 1;
        
        int cnt = 0;
        int res = -1;
        
        while(!pq.empty())
        {
            long long val = pq.top(); pq.pop();
            // cout<<val<<" ";
            cnt++;
            if(cnt == n) return val;
            
            if(mp.find(val * 2) == mp.end())
                mp[val*2] = 1 , pq.push(val*2);
            if(mp.find(val * 3) == mp.end())
                mp[val*3] = 1 , pq.push(val*3);
            if(mp.find(val * 5) == mp.end())
                mp[val*5] = 1 , pq.push(val*5);
        }
        
        
        return -1;
    }
};